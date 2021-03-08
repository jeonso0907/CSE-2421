
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


/* COpyright 2021 Neil Kirby not for disclosure 
 * header for skymath */

double decel(struct FW *fptr, double dt);
double effective_dt(struct FW *fptr);
int more_to_come(struct Sim *site);
double newX( struct FW *fptr, double dt);
double newY(struct FW *fptr, double dt);
void set_dt(struct FW *fptr, struct Sim *site) /* in seconds */;
void update_all_fireworks(struct Sim *site) /* X, Y, VY, fuse */;
void update_clock(struct Sim *site) /* sim clock and fuses */;
void update_one_firework(void *data) /* in time and space */;
