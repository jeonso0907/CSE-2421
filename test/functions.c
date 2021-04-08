
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

 
 /* COpyright 2021 Neil Kirby - not for disclosure without permission */
 /* Edited by Sooyoung Jeon */

/* the home for functions called by the list */

#include <stdio.h>

#include "debug.h"
#include "libfire.h"
#include "structs.h"

#include "memory.h"
#include "output.h"
#include "skymath.h"

/***** some callback functions are not here - 
 * output owns normal output
 * skymath owns move_fireowrk, dec_fuse
 */


/********** comparison functions *********/

/* Order of the altitude */
int altitude_order(void *data1, void *data2) {

	struct FW *f1 = data1, *f2 = data2;

	return( f1->Y > f2->Y);

}

/* Order of the launch time */
int launch_order(void *data1, void *data2) {

	struct FW *f1 = data1, *f2 = data2;

	return( f1->launch < f2->launch);

}

/********* criteria functions ************/

/* Check rather the firework is finished or not */
int is_finished(void * data) {

	struct FW *fptr = data;

	/* I don't finish until after I launch */
	if (fptr->launch > fptr->world->ET)return (0);

	/* after launch I need to be "in the air" */
	return( fptr->Y < 0.0 || fptr->fuse <= 0.0);
}

/************** action / disposal functions ********/

/* Finish the ending firework with the proper effects */
void finish(void *data) {

	struct FW *fptr = data;
	if (fptr->Y >= 0.0) {
	    if (fptr->fuse <= 0.0) detonate(fptr);
	    else {
			if(TEXT) {
			printf("ERROR: functions.c: finish: %X is still live %lf in air %lf\n", 
			fptr->code, fptr->fuse, fptr->Y);
			}
    	}
	} else {
	    impact(fptr);
	}

	free_fw(fptr);

}

/************** numeric functions ********/

/* Get the delta time in the firework */
double get_least_dt(void *data) {
	
	struct FW *fptr = data;
	return newDT(fptr);
}





