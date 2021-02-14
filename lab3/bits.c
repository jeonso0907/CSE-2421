/* Sooyoung Jeon */

#include <stdio.h>
#include "struct.h"

/*
 * Shifts and masks the bits to get the result
 */
int get_bits(int shift, unsigned int mask, unsigned int hex) {
		unsigned int bits = 0;
		hex = hex >> shift;
		bits = hex & mask;
		return bits;
}

/*
 * Gets the color with hex code
 */
int get_color(unsigned int hex) {
		return get_bits(COLOR_SHIFT, COLOR_BITS, hex);
}

/*
 * Gets the flash availity with hex code
 */
int get_flash(unsigned int hex) {
		int flash = get_bits(FLASH_SHIFT, EFFECT_BITS, hex);
		return flash;
}

/*
 * Gets the bang availity with hex code
 */
int get_bang(unsigned int hex) {
		int bang = get_bits(BANG_SHIFT, EFFECT_BITS, hex);
		return bang;
}

/*
 * Gets the day with hex code
 */
int get_day(unsigned int hex) {
		return get_bits(DAY_SHIFT, DAY_BITS, hex);
}

/*
 * Gets the month with hex code
 */
int get_month(unsigned int hex) {
		return get_bits(MONTH_SHIFT, MONTH_BITS, hex);
}

/*
 * Gets the year with hex code
 */
int get_year(unsigned int hex) {
		return get_bits(YEAR_SHIFT, YEAR_BITS, hex);
}
