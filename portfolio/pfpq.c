#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"
/*
this program has been modified to use array_pqueues instead of linked_pqueues, as it was originally written for
this change may have broken the program in some unknown way...
*/
struct track
{
	char title[20];
	char artist[20];
	int rating;
};

void print_track(any i)
{
	printf("(rating: %i,'%s', by '%s')",
		((struct track*)i)->rating,
		((struct track*)i)->title,
		((struct track*)i)->artist);
}

int le_track_d(any i, any j)
{
	return ((struct track*)i)->rating <= ((struct track*)j)->rating;
}
int le_track_a(any i, any j)
{
	return ((struct track*)i)->rating >= ((struct track*)j)->rating;
}
int le_track_n(any i, any j)
{
	int k;
	for (k=0; ((struct track*)i)->artist[k] !='\0' && ((struct track*)j)->artist[k] !='\0'; k++)
	{
		if( ((struct track*)i)->artist[k] < ((struct track*)j)->artist[k] )
			return 0;
		else if ( ((struct track*)i)->artist[k] > ((struct track*)j)->artist[k] )
			return 1;
	}
	return 1;
}

int main(int argc, char **argv)
{
	char order = 'x';
	pqueue * pq = NULL;
	while (order!='a' && order!='d' && order!='n')
	{
		printf("How would you like the playlist ordered?\nRating (a)scending\nRating (d)escending\nArtist (n)ame\n");
		scanf(" %c",&order);
		if (order == 'a')
			pq = new_bounded_pqueue(50,le_track_a);
		else if (order == 'd')
			pq = new_bounded_pqueue(50,le_track_d);
		else if (order == 'n')
			pq = new_bounded_pqueue(50,le_track_n);
		else 
			printf("\ninvalid input. Enter \"a\", \"d\" or \"n\".\n");
	}
	
	struct track *it;
	
	printf("Enter <CTRL-D> for artist or track to finish input\n");
	
	int i;
	while(1)
	{
		it = (struct track*)malloc(sizeof(struct track));
		printf("Enter track title:  "); scanf(" %[^\n]s",it->title);
		if (it->title[0] == '\0')
		{
			printf("\n");
			break;
		}
		printf("Enter artist name:  "); scanf(" %[^\n]s",it->artist);
		if (it->artist[0] == '\0')
		{
			printf("\n");
			break;
		}
		for ((it->rating) = 6 ; (it->rating) >= 6; scanf(" %d", &(it->rating))) 
			printf("Enter a rating between 0 and 5:  ");
		pqueue_insert(pq,it);
		pqueue_print(pq,print_track);
		printf("\n\n");
	}
	for (i=pqueue_size(pq); i>0; i--)
	{
		pqueue_dequeue(pq);
		pqueue_print(pq,print_track);
		printf("\n\n");
	}
}
