
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

#include "functions.h"
#include "bits.h"



/* I need this everywhere I call millisleep */
unsigned int to_ms(double sec)
{
        unsigned int ms = sec * 1000.0;
	return ms;
}

void text_header(struct Sim *site)
{
	sort(site->p2headptr, altitude_order);
    printf("\n At ET = %6.3lf (%.15lf) second:\n", site->ET, site->ET);
    printf("%8s     (%7s, %7s)'  (%7s, %7s) fps      %5s sec\n",
	"Code", "X", "Y", "VX", "VY", "Fuse");
}

void graphical_out(struct FW *fptr)
{
        int color = bits(COLOR_SHIFT, COLOR_BITS, fptr->code);
        fw_dot(color, fptr->X, fptr->Y);
}


void text_out(struct FW *fptr)
{
	if( fptr->launch <= fptr->world->ET )
	{
printf("%8X at  (%7.2lf, %7.2lf)'  (%7.2lf, %7.2lf) fps with %5.3lf sec\n",
	    fptr->code, fptr->X, fptr->Y, fptr->VX, fptr->VY, fptr->fuse);
	}
	else
	{
printf("%8X at  (%7.2lf, %7.2lf)'  Holding until %5.3lf\n",
	    fptr->code, fptr->X, fptr->Y, fptr->launch);
	}

}

/**** action function *****/
void normal_output(void *data)
{
	struct FW * fptr = data;

        if(GRAPHICS)graphical_out(fptr);;
        if(TEXT) text_out(fptr);;
}

void begin_normal_output(struct Sim *site)
{
    /* no refresh, no sleep */
	
	/* do headers & clear */
	if(TEXT)text_header(site);
	if(GRAPHICS) fw_clear();

	/* outptu each fireowrk */
	iterate(site->p2headptr, normal_output);
}

void finalize_normal_output(struct Sim *site)
{
	/* newline, refresh, sleep */
	if(TEXT)printf("\n");
	if(GRAPHICS)
	{
	    fw_refresh();
	    millisleep(to_ms(site->dt));
	}
}


void effects(struct Sim *site)
{
	deleteSome(&site->p2headptr, is_finished, finish, TEXT);
}


void fade(struct Sim *site)
{
        /* 2 seconds to let it all fade */
        double duration = 2.0;

        if(GRAPHICS)
        {
            while(duration > 0.0)
            {
                fw_clear();
                fw_refresh();
                millisleep(to_ms(site->dt));
                duration -= site->dt;
            }
        }
}


void impact(struct FW *fptr)
{
        if(TEXT)
        {
printf("RANGE SAFETY WARNING: At %.3lf sec %X (made on %d-%d-%d) impacts at (%.2lf, %.2lf)' with %.3lf seconds remaining\n",
                fptr->world->ET,
                fptr->code, bits(MONTH_SHIFT, MONTH_BITS, fptr->code),
                bits(DAY_SHIFT, DAY_BITS, fptr->code),
                bits(YEAR_SHIFT, YEAR_BITS, fptr->code),
                fptr->X, fptr->Y, fptr->fuse);
        }

        if(GRAPHICS)fw_status("RANGE SAFETY: Impact!");
}


void make_boom(struct FW *fptr)
{
        if(GRAPHICS) fw_bang();
        if(TEXT) printf("Boom at (%6.2lf, %6.2lf)'\n", fptr->X, fptr->Y);
}

void make_flash(struct FW *fptr)
{
        if(GRAPHICS) fw_flash();
        if(TEXT) printf("Flash at (%6.2lf, %6.2lf)'\n",  fptr->X, fptr->Y);
}

void make_star(struct FW *fptr)
{
        int color = bits(COLOR_SHIFT, COLOR_BITS, fptr->code);

        if(GRAPHICS) fw_star(color, fptr->X, fptr->Y);
	if(TEXT) printf("Color #%d starburst at (%6.2lf, %6.2lf)'\n", 
		color, fptr->X, fptr->Y);

}

void detonate(struct FW *fptr)
{
        int color, effect;

        if(fptr->fuse > 0.0)
        {
if(TEXT)printf("ERROR: detonate: %X fuse is %f\n", fptr->code, fptr->fuse);
            return;
        }

        /* if I get a non-zero bit from bits, fire the effect */
	if( bits(STAR_SHIFT, STAR_BITS, fptr->code)) make_star(fptr);
	if( bits(FLASH_SHIFT, FLASH_BITS, fptr->code)) make_flash(fptr);
	if( bits(BOOM_SHIFT, BOOM_BITS, fptr->code)) make_boom(fptr);
}

