
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


/* this file is mandatory so we can run 3 ways:
 * GRAHPICS set to 1 - supresses ALL text output, draws instead.
 * GRAPHICS set to 0 - text mode, VERBOSE controls what prints.
 * TEXT has 2 modes: 
 * VERBOSE to 1 to get DEBUG output 
 * VERBOSE to 0 to get only the required text output
 * Do not set TEXT or DEBUG directly; change GRAHPICS and VERBOSE instead.
 */


#define VERBOSE 0	/* 1: all messages, 0: only required mesages */
#define TEXT (! GRAPHICS)	/* do not change */
#define GRAPHICS 0	/* 1 for graphics and no text, 0 for text only */

#define DEBUG (VERBOSE && TEXT)	/* do not change this */

