/* Sooyoung Jeon */

#include "func.h"
#include <stdio.h>

/*
 * Creates the prototypes to test
 * Test the hex code to get the flash availability
 */
int main() {

		int flash = get_flash(0xF19FB36A);
		printf("Should get 1, prototype result: %d\n", flash);

		return 0;
}
