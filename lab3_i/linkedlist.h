
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


/* header file for list */

/* these are the function pointer signatures needed */

typedef void (* ActionFunction)( void *data);
typedef int (* ComparisonFunction)(void *data1, void *data2);
typedef int (* CriteriaFunction)(void *data);
typedef double (* NumericFunction)(void *data);

/* signatures that the list code provides to the outside world */

/* insert and delete need to be able to change the head pointer so you pass
 * in the address of the head pointer */

/* int returns FALSE when it fails to do the insert */
int insert(void *p2head, void *data, ComparisonFunction goesInFrontOf, 
		int verbose);
void deleteSome(void *p2head, CriteriaFunction mustGo, 
		ActionFunction disposal, int verbose);

/* iterate and sort do not change the nodes, so you pass in the head
 * pointer and not the address of the head pointer */
void iterate(void *head, ActionFunction doThis);

/* sort moves data, not nodes, so head won't change */
void sort(void *head, ComparisonFunction goesInFrontOf);

/* some returns true if at least one item passes the test 
 * returns false if nothing in the list */
int some(void *head, CriteriaFunction someTest);

/* least returns least value of all calls to numeric function 
 * returns NaN if list is empty.  if(x != x) is true when x is NaN */
double least(void *head, NumericFunction compute_this);




