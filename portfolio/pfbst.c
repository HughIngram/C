/* program: pfbst
*  function: portfolio excersise demonstrating the use of the BST data structure
*  author: Hugh Ingram. Based on a bst_demo by drs
*/

#include <stdlib.h>
#include <stdio.h>
#include "any.h"
#include "bst_char.h"

#define NEWLINE printf("\n");

void print_char(char c)
{
	putchar(c);
}
char bst_char_iterate_plusone(char item)
{
	return item + 1;
}
char bst_char_iterate_minusone(char item)
{
	return item - 1;
}
int main()
{
	bst_char *t = new_bst_char();
	char a, c;
	bst_char_insert(t,'N');
	bst_char_insert(t,'T');
	bst_char_insert(t,'Q');
	bst_char_insert(t,'P');
	bst_char_insert(t,'D');
	bst_char_insert(t,'C');
	bst_char_insert(t,'F');
	
//	bst_char_simple_print(t,print_char);
	bst_char_pretty_print(t);
	printf("Action? (q)uit; (a)dd; is(b)alanced?; (d)elete; (i)terate; ([)prefix; (-)infix; (])postfix; ");
	scanf(" %c", &a);
	while( a != 'q')
	{
		switch (a)
		{
			case 'q':
				break;
			case 'a':
				scanf(" %c", &c);
				bst_char_insert(t,c);
				break;
			case 'b':
				printf("Is the tree balanced? ");
				if (bst_char_isbalanced(t))
					printf("TRUE\n");
				else
					printf("FALSE\n");
				break;
			case 'd':
				scanf(" %c", &c);
				bst_char_delete(t,c);
				break;
			case '[':
				printf("Prefix traversal: ");
				bst_char_preorder_print(t,print_char);
				putchar('\n');
				break;
			case '-':
				printf("Infix traversal: ");
				bst_char_inorder_print(t,print_char);
				putchar('\n');
				break;
			case 'i':
				printf("how would you like to modify the tree? (a)dd one; (s)ubtract one; ");
				scanf(" %c", &c);
				if (c=='a')
					bst_char_iterate(t,bst_char_iterate_plusone);
				if (c=='s')
					bst_char_iterate(t,bst_char_iterate_minusone);
				putchar('\n');
				break;
			case ']':
				printf("Postfix traversal: ");
				bst_char_postorder_print(t,print_char);
				putchar('\n');
				break;
			default:
				printf("Input not recognised\n");
				break;
		}
//		bst_char_simple_print(t,print_char);
		bst_char_pretty_print(t);
		printf("Action? (q)uit; (a)dd; is(b)alanced?; (d)elete; (i)terate; ([)prefix; (-)infix; (])postfix; ");
		scanf(" %c", &a);
	}
	NEWLINE
	return 0;
}
