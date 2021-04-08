
/* Instructor supplied driver code for SP 21 Lab 5 
 * Do not modify this code.
 */

#include <stdio.h>
#include <stdlib.h>


long translate(char *source, char *dest);
long verify(char *source, char *dest);

int main()
{
	char buffer[10];
	char instr[] = { (char) 0x74, (char) 0xF6, 
	    (char) 0x02, 
	    (char) 0x24, (char) 0x57, (char) 0x36, (char) 0xB6, (char) 0x37, 
	    (char) 0x12,
	    '\0'};
	long count;

	/* count = translate(instr, buffer); */
	/* verify will rat you out if you do not properly use the callee
	 * saved registers in translate.  Call it and it calls translate
	 */
	count = verify(instr, buffer);

	printf("The input string\n'%s'\nbecomes\n'%s'\n", instr, buffer);
	printf("%d characters translated\n", count);


	
	return EXIT_SUCCESS;
}
	
