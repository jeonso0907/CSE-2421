/* Sooyoung Jeon */

#include <stdio.h>
#include "include.h"

int Double(int x)
{
	return 2* x;
}

int main()
{
	int i = INIT, j;
	
	printf("Before, i=%d\n", i);
	j = Double(i);
	printf("After, j=%d\n", j);
	/* Rreturning 0 to the system signifies no erros */
	return 0;
}

