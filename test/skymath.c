
/* Copyright 2021 Neil Kirby.  Not for disclosure without written
 * permission.  */

/* Instructor supplied Lab 3 code.  */

/* THis file may have shortcomings when measured by the grading standards
 * of this class.  If you use this code, you are expected to fix those
 * shortcomings or recieve points off.  Finding and commenting on those
 * shortcomings is the subject of a homework.  
 *
 * One purpose for this is to show how following those standards makes code
 * more readable and easier to modify.
 *
 * Another purpose is to force you to fully understand the code before
 * using it so that you can debug your changes and understand what is going
 * on.
 *
 * Chanigning this code: You are required to comment all functions that you
 * make changes to.  Put your name and the changes made nad the reason why
 * in your comments.  Talk about why, talk about what you are thinking,
 * don't write a comment that says what the code already says.  The code
 * says what you wrote, the comment says what you thought.  Feel free to
 * leave notes for yourself in the comments as you work so you can come
 * back and pick up where you left off.
 */


/* copyright 2021 Neil Kirby */
/* Edited by Sooyoung Jeon */

#include <stdio.h>
#include <stdlib.h>

#include "libfire.h"
#include "linkedlist.h"

#include "structs.h"
#include "debug.h"
#include "physics.h"
#include "functions.h"

/********* salvaged / ported routines *************/

/* Calculate the new delta time */
double newDT(struct FW *fptr) {

	return (0.25 * fw_get_delta_Y() / fptr->VY);
}

/* (SOOYOUNG JEON) Edited the set_dt by adding function newDT to avoid the two jobs in a function */

/* Set up the appropriate delta time for the fireworks */
void set_dt(struct Sim *site) {

	/* to get two hits in X I need 4 hits in y */
	site->dt = least(site->p2headptr, get_least_dt);
}

/****** x, y , vx, vy related ******/

/*** constant V  postion update */
double newX( struct FW *fptr, double dt) {

    return( fptr->X + fptr->VX *dt);
}

/* with accel */
double newY(struct FW *fptr, double dt) {

        return( fptr->Y + fptr->VY * dt + 0.5 * GRAVITY * dt * dt);
}

/* Calculate the new Y velocity */
double get_newVY(struct FW *fptr, double dt) {

		return fptr->VY + GRAVITY * dt;
}

/* (SOOYOUNG JEON) Edited the decel_and_warn function to avoid the two jobs in a function */

/* If the Y velocity changed as negative, print out the range safety messsage */
double decel_and_warn(struct FW *fptr, double dt) {

	double newVY = get_newVY(fptr, dt);
	
	if ( newVY < 0.0 && fptr->VY >= 0.0 && fptr->fuse > 0.0) {
	    if (TEXT)printf("RANGE SAFETY WARNING: %X is falling at %.1lf' alt and %.1lf' downrange with %.3lfs till detonation.\n", fptr->code, fptr->Y, fptr->X, fptr->fuse);
	    if (GRAPHICS)fw_status("RANGE SAFETY: Freefall!");
	}
	return newVY;
}


/******** end salvaged routines *******/

/******** new for lab 3 dcode here on down ********/

/* Set the appropriate case delta time and print the debug message if there is    one */
double set_dt_and_debug(struct FW *fptr, struct Sim *site, int debug) {

	double rval = 0.0;
	
	if (debug == HOLD) {
			rval = 0.0;
			if (DEBUG)printf("effective_dt: %X HOLD ET=%.4lf, L=%.4lf, F=%.4lf, dt=%4lf. rval= %.4lf\n", fptr->code, site->ET, fptr->launch, fptr->fuse, site->dt, rval);
	} else if (debug == IN_AIR) {
			rval = site->dt; /* normal flight */
	    	if (DEBUG)printf("effective_dt: %X IN AIR  ET=%.4lf, L=%.4lf, F=%.4lf dt=%4lf. rval= %.4lf\n", fptr->code, site->ET, fptr->launch, fptr->fuse, site->dt, rval);
	} else {
	    	rval = (site->ET - fptr->launch);
	    	if (DEBUG)printf("effective_dt: %X LAUNCH ET=%.4lf, L=%.4lf, F=%.4lf dt=%4lf. rval= %.4lf\n", fptr->code, site->ET, fptr->launch, fptr->fuse, site->dt, rval);
	}
	
	return rval;
}

/* (SOOYOUNG JEON) Edited the effective_dt function by adding helper 
 * function set_dt_and_debug to set new delta time and print the debug message to not 
 * exceed the 10 line limit */

/* for many reasons, the dt we need might not be the full dt of the sim.  
 * NOTE: call this before decrementing fuse, and not after 
 */
double effective_dt(struct FW *fptr) {

	/* compare ET to launch time and dt: Did I just launch?
	 * If so, I have a short dt since I launched between ticks.
	 * WIll I explode this update?  I won't get as far as normal.
	 */
	double rval = 0.0;
	struct Sim *site = fptr->world;

	if (site->ET <= fptr->launch)  {
	    rval = set_dt_and_debug(fptr, site, HOLD);
	} else if (site->ET > fptr->launch + site->dt) {
	    rval = set_dt_and_debug(fptr, site, IN_AIR);
	} else {
		rval = set_dt_and_debug(fptr, site, LAUNCH);
	    /* this is the update I launch on, might only get partway into 
	     * the air */
	}

	/* and finally, will I detonate?  If so, won't get as far.  This is
	 * separate from the various cases above - all of them need this
	 * check.  */
	if (rval > 0 && rval >= fptr->fuse) {
	    rval = fptr->fuse;
	    if (DEBUG)printf("effective_dt: %X  - clipping to fuse time.\n", fptr->code);
	}

	return rval;
}

/* Check rather the nodes in the linked list i empty or not */
int more_to_come(struct Sim *site) {

	/* I may have some that have not launched yet */
	return (site->p2headptr != NULL);
}

/************** action function *********/

/* Update a single firework data */
void update_one_firework(void *data) { /* in time and space */ 

	struct FW *fptr = data;
	/* my effective dt may be shorter than the normal dt */
	double dt = effective_dt(fptr);

	/* note that this has an interaction with effective_dt */
	fptr->fuse -= dt;

	fptr->X = newX(fptr, dt);
	fptr->Y = newY(fptr, dt);
	fptr->VY = decel_and_warn(fptr, dt);
}

/* Iterate to update all fireworks' data */
void update_all_fireworks(struct Sim *site) { /* X, Y, VY, fuse */

	iterate( site->p2headptr, update_one_firework);
}

/* Update the elapsing time */
void update_clock(struct Sim *site) { /* sim clock and fuses */

	site->ET += site->dt;
}


