#include <stdio.h>
#include <stdlib.h>
#include "queue_int.h"

#define RAND_NO_SEED 	128475
#define MAX_BUFF_LEN  	3
#define U1_SND		0
#define U2_SND		1
#define P1_RCV		2
#define P2_RCV		3


static int U1_suspended = 0;
static int U2_suspended = 0;
static int P1_suspended = 1;
static int P2_suspended = 1;

int simulated_activity()
{
	int r = rand()%99;
	if (r < 35)
		return U1_SND;
	else if (r < 70)
		return U2_SND;
	else if (r <85)
		return P1_RCV;
	else
		return P2_RCV;
}

static int item = 1;
int next_item() {return item++; }
void printint(int i) { printf("%i",i); }

int main(int argc, char **argv)
{
	queue_int *buff_P1 = new_bounded_queue_int(MAX_BUFF_LEN);
	queue_int *buff_P2 = new_bounded_queue_int(MAX_BUFF_LEN);
	srand(RAND_NO_SEED);
	int a;
	
	while (1) {
		sleep(1);
		
		if (U1_suspended) printf("\nU1 suspended");
		else 		 printf("\nU1 active");
		
		if (U2_suspended) printf("\nU2 suspended\n");
		else 		 printf("\nU2 active\n");
		
		if (P1_suspended) printf("\nP1 suspended");
		else 		 printf("\nP1 active");
		
		if (P2_suspended) printf("\nP2 suspended\n");
		else 		 printf("\nP2 active\n");
		
		a = simulated_activity();
		
		printf("\nbuff_P1: "); queue_int_print(buff_P1,printint);
		printf("\nbuff_P2: "); queue_int_print(buff_P2,printint);
		
		switch( a ) {
		case U1_SND:
			if(queue_int_isfull(buff_P1) && queue_int_isfull(buff_P2))
				U1_suspended = 1;
			else if (!queue_int_isfull(buff_P1)) 
			{
				U1_suspended = 0;
				queue_int_enqueue(buff_P1,next_item());
			}
			else
			{
				U1_suspended = 0;
				queue_int_enqueue(buff_P2,next_item());
			}
			break;
		case U2_SND:
			if(queue_int_isfull(buff_P1) && queue_int_isfull(buff_P2))
				U2_suspended = 1;
			else if (!queue_int_isfull(buff_P2)) 
			{
				U2_suspended = 0;
				queue_int_enqueue(buff_P2,next_item());
			}
			else
			{
				U2_suspended = 0;
				queue_int_enqueue(buff_P1,next_item());
			}
			break;
		case P1_RCV:
			if (queue_int_isempty(buff_P1))
				P1_suspended = 1;
			else
			{
				P1_suspended = 0;
				queue_int_dequeue(buff_P1);
			}
			break;
		case P2_RCV:
			if (queue_int_isempty(buff_P2))
				P2_suspended = 1;
			else
			{
				P2_suspended = 0;
				queue_int_dequeue(buff_P2);
			}
		}
		printf("\n\n============================\n");
		
		printf("\nSimulated activity: ");
		if (a==U1_SND) printf("U1_SND\n");
		else if (a==U2_SND) printf("U2_SND\n");
		else if (a==P1_RCV) printf("P1_RCV\n");
		else if (a==P2_RCV) printf("P2_RCV\n");
	}
}
