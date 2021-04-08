/*
 * Sooyoung Jeon
 * Lab3: listproto.c (Prototype to test the linked list method for struct);
 */

#include <stdio.h>
#include "struct.h"
#include "linkedlist.h"

/* a criteria function */
int always_true(void *data)
{
	/* no actual determination, always return true */
	/* a real criteria would assign data to a real pointer type and then
	 * do something with that to say yes or no */
	return(1==1);
}


/* a comparison function that compares the elapsing time of two fireworks*/
int firstchar(void *data1, void *data2)
{
	struct Firework *f1 = data1, *f2 = data2;

	return( f1->time < f2->time);
}

/* an action function to print a string */
void printIt(void *data)
{
	struct Firework *f;
	f = data;
	printf("ET is : %lf\n", f->time);

}

int main()
{

	void *list = NULL; /* MUST set it to NULL to begin with! */
	
	/* Initialize four firework rockets with its own elapse time */
	struct Firework rocket1, rocket2, rocket3, rocket4;
	rocket1.time = 10;
	rocket2.time = 5;
	rocket3.time = 4;
	rocket4.time = 8;

	/* test insert */
	insert(&list, &rocket1, firstchar, 1);
	/* now test iterate */
	printf("Calling iterate\n");
	iterate(list, printIt);
	    /* the code to here is a good prototype that tests insert and iterate */

	/* test insert again - this will test the comparison as well */
	insert(&list, &rocket2, firstchar, 1);
	/* now test iterate */
	printf("Calling iterate\n");
	iterate(list, printIt);

	/* test insert again - this will test the comparison as well */
	insert(&list, &rocket3, firstchar, 1); 
	/* now test iterate */
	printf("Calling iterate\n");
	iterate(list, printIt);

	/* test insert again - this will test the comparison as well */
	insert(&list, &rocket4, firstchar, 1); 
	/* now test iterate */
	printf("Calling iterate\n");
	iterate(list, printIt);


	/* the code to here is a good prototype that proves comparison is correct */

	    /* I could write a different comparison function and use it to call sort (then iterate) to 
	     * show how sort works */
	printf("Calling sort\n");
	sort(list, firstchar);
	printf("Calling iterate\n");
	iterate(list, printIt);

	/* now test deleteSome */
	printf("Deleting entire list\n");
	/* for "disposal" I print the string since I didn't use malloc to allocate it */
	deleteSome(&list, always_true, printIt, 1);
	/* prove the list is empty */
	printf("Calling iterate\n");
	iterate(list, printIt);
	printf("Done!\n");
		/* code to here is a final prototype proving that delete works */

	return 0;
}

	
