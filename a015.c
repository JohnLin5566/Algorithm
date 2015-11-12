/* Linked list practice */
#include<stdio.h>
#include<stdlib.h>

struct node{
	int x;
	struct node *next;
};

int main(){
	struct node *root;
	struct node *conductor;

	root = malloc( sizeof(struct node) );
	root->x = 12;
	root->next = 0;
	printf("%%p is %p\n", root);
	printf("root->next is %p\n", root->next);
	printf("root->x is %d\n", root->x);


	conductor = root;
	if ( conductor != 0 ){
		while ( conductor->next !=0 ){
			conductor = conductor->next;
		}
	}
	printf("%%p is %p\n", conductor);
	printf("conductor->next is %p\n", conductor->next);

	/* create a node at the end of the list */
	conductor->next = malloc( sizeof(struct node) );
	printf("%%p is %p\n", conductor);

	conductor = conductor->next;
	printf("conductor->next is %p\n", conductor->next);

	if ( conductor == 0 ){
		printf( "Out of memory\n" );
		return 0;
	}

	/* initialize the new memory */
	conductor->next = 0;
	conductor->x = 42;
	printf("conductor->next is %p\n", conductor->next);
	printf("conductor->x is %d\n", conductor->x);


	return 0;
}
