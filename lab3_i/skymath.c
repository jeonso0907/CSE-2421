
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

#include <stdio.h>
#include <stdlib.h>

#include "libfire.h"
#include "linkedlist.h"

#include "structs.h"
#include "debug.h"
#include "physics.h"

/********* salvaged / ported routines *************/


void set_dt(struct FW *fptr, struct Sim *site) /* in seconds */
{
	/* to get two hits in X I need 4 hits in y */
	double candidate = (0.25 * fw_get_delta_Y() / fptr->VY);
	if( site->dt == 0.0 || site->dt > candidate) site->dt = candidate;
}

/****** x, y , vx, vy related ******/


/*** constant V  postion update */
double newX( struct FW *fptr, double dt)
{
    return( fptr->X + fptr->VX *dt);
}

/* with accel */
double newY(struct FW *fptr, double dt)
{
        return( fptr->Y + fptr->VY * dt + 0.5 * GRAVITY * dt * dt);
}

double decel_and_warn(struct FW *fptr, double dt)
{
	double newVY = fptr->VY + GRAVITY * dt;
	
	if( newVY < 0.0 && fptr->VY >= 0.0 && fptr->fuse > 0.0)
	{
	    if(TEXT)printf("RANGE SAFETY WARNING: %X is falling at %.1lf' alt and %.1lf' downrange with %.3lfs till detonation.\n", fptr->code, fptr->Y, fptr->X, fptr->fuse);
	    if(GRAPHICS)fw_status("RANGE SAFETY: Freefall!");
	}
	return newVY;
}


/******** end salvaged routines *******/

/******** new for lab 3 dcode here on down ********/

/* for many reasons, the dt we need might not be the full dt of the sim.  
 * NOTE: call this before decrementing fuse, and not after 
 */
double effective_dt(struct FW *fptr)
{
	/* compare ET to launch time and dt: Did I just launch?
	 * If so, I have a short dt since I launched between ticks.
	 * WIll I explode this update?  I won't get as far as normal.
	 */
	double rval = 0.0;
	struct Sim *site = fptr->world;

	if (site->ET <= fptr->launch) 
	{
	    rval= 0.0; /* not launched yet */
if(DEBUG)printf("effective_dt: %X HOLD ET=%.4lf, L=%.4lf, F=%.4lf, dt=%4lf. rval= %.4lf\n",
	    fptr->code, site->ET, fptr->launch, fptr->fuse, site->dt, rval);
	}
	else if (site->ET > fptr->launch + site->dt)
	{
	    rval = site->dt; /* normal flight */
if(DEBUG)printf("effective_dt: %X IN AIR  ET=%.4lf, L=%.4lf, F=%.4lf dt=%4lf. rval= %.4lf\n",
	    fptr->code, site->ET, fptr->launch, fptr->fuse, site->dt, rval);
	}
	else
	{

	    /* this is the update I launch on, might only get partway into 
	     * the air */
	    rval = (site->ET - fptr->launch);
if(DEBUG)printf("effective_dt: %X LAUNCH ET=%.4lf, L=%.4lf, F=%.4lf dt=%4lf. rval= %.4lf\n",
	    fptr->code, site->ET, fptr->launch, fptr->fuse, site->dt, rval);
	}

	/* and finally, will I detonate?  If so, won't get as far.  This is
	 * separate from the various cases above - all of them need this
	 * check.  */
	if(rval > 0 && rval >= fptr->fuse) 
	{
	    rval = fptr->fuse;
if(DEBUG)printf("effective_dt: %X  - clipping to fuse time.\n", fptr->code);
	}

	return rval;
}

int more_to_come(struct Sim *site)
{
	/* I may have some that have not launched yet */
	return (site->p2headptr != NULL);
}

/************** action function *********/
void update_one_firework(void *data) /* in time and space */
{
	struct FW *fptr = data;
	/* my effective dt may be shorter than the normal dt */
	double dt = effective_dt(fptr);

	/* note that this has an interaction with effective_dt */
	fptr->fuse -= dt;

	fptr->X = newX(fptr, dt);
	fptr->Y = newY(fptr, dt);
	fptr->VY = decel_and_warn(fptr, dt);
}

void update_all_fireworks(struct Sim *site) /* X, Y, VY, fuse */
{
	iterate( site->p2headptr, update_one_firework);
}


void update_clock(struct Sim *site) /* sim clock and fuses */
{
	site->ET += site->dt;
}

