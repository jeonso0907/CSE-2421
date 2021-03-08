
/* Copyright 2021 Neil Kirby.  Not for disclosure without written
 * permission.  */

/* Instructor supplied Lab 3 code.  */

/* THis file may have shortcomings when measured by the grading standards
 * of this class.  If you use this code, you are expected to fix those
 * shortcomings or recieve points off.  Finding and commenting on those
 * shortcomings is the subject of a homework.  
 *
 * One purpose for this is to show how following those standards makes code
 * more readable and easier to modify.
 *
 * Another purpose is to force you to fully understand the code before
 * using it so that you can debug your changes and understand what is going
 * on.
 *
 * Chanigning this code: You are required to comment all functions that you
 * make changes to.  Put your name and the changes made nad the reason why
 * in your comments.  Talk about why, talk about what you are thinking,
 * don't write a comment that says what the code already says.  The code
 * says what you wrote, the comment says what you thought.  Feel free to
 * leave notes for yourself in the comments as you work so you can come
 * back and pick up where you left off.
 */


/* header file for bits.c */


/* used to get data out of the code */
#define STAR_SHIFT 31
#define STAR_BITS 1
#define FLASH_SHIFT 30
#define FLASH_BITS 1
#define BOOM_SHIFT 29
#define BOOM_BITS 1

#define COLOR_SHIFT 24
#define COLOR_BITS 4

#define DAY_SHIFT 16
#define DAY_BITS 8

#define MONTH_SHIFT 12
#define MONTH_BITS 4

#define YEAR_SHIFT 0
#define YEAR_BITS 12



/* signatures below here */
int bits(int shift, int many, int source);

