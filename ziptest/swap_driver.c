
#include <stdio.h>
#include <stdlib.h>

unsigned char swap(unsigned char byte);
unsigned char shim(unsigned char byte);

int main()
{
	unsigned char in, out;

	for(in = 0x20; in< 0x7F; in++)
	{
	    /* your code has to run calling shim.  But you can test
	     * with a direct call to swap. */

	    /* comment out one of these two */
	    /* out = swap(in); */
	    out = shim(in);
	    printf("'%c'	0x%02X	becomes 	'%c'	0x%02X\n", 
		in, in, out, out);


	}

	return EXIT_SUCCESS;
}
