/* Sooyoung Jeon */

#include "func.h"
#include <stdio.h>

/*
 * Creates the prototype to test
 * Test for getting the color from the hex code
 */
int main() {

		int color = get_color(0xA30B46AA);
		printf("The color number is %d\n", color);

		return 0;
}
