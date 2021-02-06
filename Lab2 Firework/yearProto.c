/* Sooyoung Jeon */

#include "func.h"
#include <stdio.h>

/*
 * Create the prototype to test
 * Test the hex code to get the year
 */
int main() {

		int year = get_year(0xA39BF7E5);
		printf("Should get 2021, prototype result: %d\n", year);

		return 0;
}
