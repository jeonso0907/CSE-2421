
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


/* copyright 2021 Neil Kirby - not for disclosure without permission */

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

#include "debug.h"
#include "structs.h"

#include "skymath.h"
#include "functions.h"

#include "altmem.h"

void free_fw(struct FW *dfw)
{
	static int free_count = 0;
	if(dfw)
	{
	    free_count++;
	    if(TEXT)printf("DIAGNOSTIC: Freeing firework with code %X.  %d freed.\n", dfw->code, free_count);
	    alternative_free(dfw);
	}
}

/* take a fw and copy it to new dynamic memory if I can */
struct FW *to_dynamic_memory(struct FW *fptr)
{
	struct FW *dfw = NULL;
	static int allocations = 0;

	if(dfw = alternative_malloc(sizeof(*dfw)))
	{
	    /* success! do the copy */
	    allocations++;
	    *dfw = *fptr;
	    if(TEXT) printf("DIAGNOSTIC: Allocating space for code %X.  %d allocated.\n", dfw->code, allocations);
	}
	else
	{
if(TEXT)printf("ERROR: memory.c: to_dynamic_memory: malloc failed\n");
	}

	return dfw;
}

void clone_to_list(struct FW *fptr, struct Sim *site)
{
	struct FW *dfw; /* not an airport, but a dynamic memory firework */


	if( dfw = to_dynamic_memory(fptr) )
	{
	    if(insert(&site->p2headptr, dfw, launch_order, TEXT))
	    {
		/* do I want to set dt for site here? */
		/* only if we succeeded in getting it into the list */
		set_dt(dfw, site);
	    }
	    else
	    {
	    	/* give back the dynamic memory */
		free_fw(dfw);
	    }
	}
}

