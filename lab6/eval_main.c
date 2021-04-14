


/* SP21 Lab 6 Insctructor supplied code.  Not for outside disclosure
 * Copyright 2021 Neil Kirby
 * Do not remove this copyright notice.
 */

#include <stdio.h>
#include <stdlib.h>

#include "device.h"

/* from device.h, shown here to make it easier to code
struct Device
{	
	char name[20];
	short adjustments[8];
	short avg;
};
*/



unsigned short evaluate(struct Device *thing);


int main()
{
	unsigned short var;
	struct Device actual = { "Fell down stairs",
	    { 0x7ff0, (unsigned short)0x800f, 0x7ffe, (unsigned short)0x8001, 
	    0x7ffd, (unsigned short)0x8002, 0x7fff, 0x7f00}, 
	    3 };
	    
	struct Device actual2 = { "On right side",{ -300, -321, -320, -332, -320, -313, -310, -314}, 5};
	    
	struct Device *thing = & actual2;
	

	printf("eval_driver: %s currently has an adjustment of %d\n", 
	    thing->name, thing->avg);
	var = evaluate(thing);
	printf("\neval_driver: new adjustment is %d, variability is %u\n", 
	    thing->avg, var);


	return(EXIT_SUCCESS);
}


