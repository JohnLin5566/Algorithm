/* linked list practice */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int x;
	struct node *next;
};

int main()
{

	/* This will be the unchanging first node */
	struct node *root;      
	printf("%%p is %p\n", root);

	/* Now root points to a node struct */
	root = (struct node *) malloc( sizeof(struct node) ); 
	printf("%%p is %p\n", root);

	/* The node root points to has its next pointer equal to a null pointer 
	*        set */
	root->next = 0;
	printf("root->next is %p\n", root->next);
	
	/* By using the -> operator, you can modify what the node,
	*        a pointer, (root in this case) points to. */
        root->x = 5;   
	printf("root->x is %d\n", root->x);

	printf("root is %p\n", root);
}

