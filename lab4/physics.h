
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

/* how big is the sky? */
/* Edited by Sooyoung Jeon */
 
/* (SOOYOUNG JEON) To avoid the 10 line limist in effective_dt function, 
 * define the case number for each effective delta time case  to avoid the magic number */
  
#define HOLD 1 /* Case for the fireworks not launcehd yet */
#define IN_AIR 2 /* Case for the fireworks launched and in the air */
#define LAUNCH 3 /* Case for the fireworks about to launch */

#define GRAVITY -32.17405



