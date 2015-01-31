/* This program uses 'c1_demo1' written by drs as a template 
* Program: pfclist
* Function: Demonstrating the use of the clist data structure and clist_backspace function
* Author:   Hugh Ingram.
*/

#include <stdlib.h>
#include <stdio.h>
#include "any.h"
#include "clist.h"

#define MAX_INTS 100
#define NEWLINE printf("\n");

/*************************************************************************************
* Functions that operate on references to int values
************************************************************************************/

int even_int( any d )		// even(d) ?
{
	return ((*(int*)d) % 2) == 0;
}
void double_int( any d )	// d*=2
{
	*(int*)d = *(int*)d * 2;
}
//add a function to square an int
void square_int ( any d )
{
	*(int*)d = (*(int*)d) * (*(int*)d);
}
/*************************************************************************************
* Functions to display the contents of a list
************************************************************************************/

void show_int( any d )
{
	printf("%3i",*(int*)d);
}
void show_list(clist *cl, char * caption)
{
	any d;
	printf("CAPTION: \"%s\"", caption);
	printf("\n clist size:		%3i", clist_size(cl)	     );
	printf("\n clist_isempty:		 %3i",clist_isempty(cl));
	printf("\n clist_cursor_inlist:	%3i",  clist_cursor_inlist(cl));
	printf("\n item at cursor:	");
	d = clist_get_item(cl);
	if (d==NULL)
		printf("NULL");
	else
		show_int(d);
	printf("\n clist_print:		");
	clist_print(cl, &show_int);
	NEWLINE
}

int main()
{
	clist *xs;
	any j;
	
	/*************************************************************************************
	* A pool of data values is needed to be placed into the list during various
	* test cases. A simple approach is to create an array of ints in which the
	* index is equal to the value. The required "pointer to an integer" can then
	* be obtained by using the address of a particular array element.
	* Be careful though: these are mutable objects (having reference semantics)
	* and each new test case should re-initialise the array to avoid previous
	* modifications affecting behaviour (e.g. as would happen with a call to the
	* iterate function).
	************************************************************************************/
	int i, d[MAX_INTS];
	for (i=0;i<MAX_INTS;i++) d[i]=i;
	
	xs = new_clist();
	show_list(xs,"Empty");
	NEWLINE
	
	clist_ins_before(xs, &d[1]);
	clist_ins_before(xs, &d[2]);
	clist_ins_before(xs, &d[3]);
	clist_ins_before(xs, &d[4]);
	show_list(xs,"Inserted four integers before cursor");
	NEWLINE
	clist_ins_after(xs, &d[5]);
	clist_ins_after(xs, &d[6]);
	clist_ins_after(xs, &d[7]);
	clist_ins_after(xs, &d[8]);
	show_list(xs,"Inserted four integers after cursor");
	NEWLINE
	
	clist_iterate(xs, square_int);
	show_list(xs,"Squared numbers in the list");
	NEWLINE
	
	clist_goto_next(xs);
	clist_goto_next(xs);
	clist_goto_next(xs);
	show_list(xs,"Moved cursor");
	NEWLINE
	
	clist_backspace(xs);
	show_list(xs,"Executed backspace");
	NEWLINE
	
	clist_goto_head(xs);
	show_list(xs,"Moved cursor to head");
	NEWLINE
	
	clist_backspace(xs);
	show_list(xs,"Executed backspace, to demonstrate behaviour when trying to backspace at head");
	
	clist_release(xs);
	return 0;
}
