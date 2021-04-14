
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

struct Device things[] =
{
    { "Museum Quality",{ 0, 1, 0, -1, 0, -1, 0, 1}, 1 },
    { "Fell off truck",
        { 0x7fff, 0x7fff, 0x7fff, 0x7fff, 0x7fff, 0x7fff, 0x7fff, 0x7fff},
    2 },

    /* the casts are there since C constants are ints and you can't make
     * them shorts and negative numbers look like overflow */
    { "Fell down stairs",
	{ 0x7ff0, (unsigned short)0x800f, 0x7ffe, (unsigned short)0x8001, 
	0x7ffd, (unsigned short)0x8002, 0x7fff, 0x7f00}, 
    3 },

    { "On left side",{ 10, 11, 10, 12, 10, 13, 10, 14}, 4 },
    { "On right side",{ -300, -321, -320, -332, -320, -313, -310, -314}, 5 }
};


/*
struct Device *inventory(struct Device *things[], int count);
*/


/* take will verify register usage in inventory */

struct Device *take(struct Device *things[], int count);


int main()
{

	struct Device *pointers[1 + sizeof(things) / sizeof(things[0])] 
		= {NULL};
	const int count =  sizeof(things) / sizeof(things[0]);

	struct Device *worst = NULL;

	int i;


	for (i=0; i< count; i++)
	{
	    printf("Loading %s into pointers\n", things[i].name);
	    pointers[i] = &things[i];
	}
	pointers[i] = NULL;

	/* take inventory - take calls inventory */
	worst = take(pointers, count);

	printf("lab6 main: The worst is %s\n", worst->name);


	return(EXIT_SUCCESS);
}

