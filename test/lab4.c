
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

#include "structs.h"
#include "debug.h"
#include "skymath.h"
#include "output.h"
#include "memory.h"

/* Run the simulation of the firework */
void run_sim(struct Sim *site) {

	/* double dt = get_dt(VY); */

	while (more_to_come(site)) {
		/* output both ways */
	    begin_normal_output(site); /* no refresh, no sleep */
	    update_clock(site); /* sim clock */
	    update_all_fireworks(site); /* X, Y, VY , fuse*/
	    effects(site); /* includes impact */
	    finalize_normal_output(site); /* newline, refresh, sleep */
	}
	fade(site);
}

/* Read the file not inputed as a command line */
int read_loop_no_command(struct Sim *site) {

	int items;
	struct FW actual, *fptr = &actual;

	/* all fireworks are in my world at ground level */
	fptr->world = site;
	fptr->Y = 0.0;

	while ( 6 == (items = scanf("%lf %x %lf %lf %lf %lf", 
	    &fptr->launch, &fptr->code, &fptr->fuse, &fptr->X, &fptr->VX, 
	    &fptr->VY)))
	{
	    clone_to_list(fptr, site);
	}

	return items;
}

/* Read the file inputed as a command line */
int read_loop_command(struct Sim *site, FILE *input_file) {

	int items;
	struct FW actual, *fptr = &actual;

	/* all fireworks are in my world at ground level */
	fptr->world = site;
	fptr->Y = 0.0;

	while ( 6 == (items = fscanf(input_file, "%lf %x %lf %lf %lf %lf", 
	    &fptr->launch, &fptr->code, &fptr->fuse, &fptr->X, &fptr->VX, 
	    &fptr->VY))) {
	    clone_to_list(fptr, site);
	}

	return items;
}

/* (SOOYOUNG JEON) Removed the new world function above and just initialized in this function
 * It is uneccessary to use another function just to initialize the variable
 * get and run the world data */
 
 /* Set up the data in the structs to start simulation */
int data_sequence(FILE *input_file) {

	int rval;
	/* Initialized the sim structure's initial values */
	struct Sim launch_site = {0.0, 0.0, NULL};
	
	if (input_file != NULL) rval = read_loop_command(&launch_site, input_file);
	else rval = read_loop_no_command(&launch_site);
	run_sim(&launch_site);

	return rval;
}

/* Main function where contains the command line to excute the input file */
int main(int argc, char** argv) {

	double start, runtime;
	int items;
	FILE *input_file;

	start = now();
	if( TEXT || ( GRAPHICS && fw_initialize()) ) {
		if (argc > 1) input_file = fopen(argv[1], "r"); /* Read the input file fomr the command line */
	    items = data_sequence(input_file);
	    if(GRAPHICS) fw_teardown();
	    /* I don't need to protect this print since we already did
	     * teardown */
	    printf("Done reading: scanf returned %d\n", items);
	} else {
	    printf("Failed to init.\n");
	}
	runtime = now() - start;
	printf("Total run time is %.9lf seconds.\n", runtime);

	return(EXIT_SUCCESS);
}
