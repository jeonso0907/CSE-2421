/* Sooyoung Jeon */

/* Define the fading time */
#define FADE 2

/* Define the color shift and bits to mask  */
#define COLOR_SHIFT 24
#define COLOR_BITS 0xF

/* Define the effect shift and bits to mask */
#define FLASH_SHIFT 30
#define BANG_SHIFT 29
#define EFFECT_BITS 0x1

/* Define the made date shift and bits to mask */
#define DAY_SHIFT 16
#define DAY_BITS 0xFF
#define MONTH_SHIFT 12
#define MONTH_BITS 0xF
#define YEAR_SHIFT 0
#define YEAR_BITS 0xFFF

int get_color(unsigned int hex);
int get_flash(unsigned int hex);
int get_bang(unsigned int hex);

