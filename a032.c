/* C program for linked list implementation of stack */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* prototype of the linked list structure */
struct StackNode{
	int data;
	struct StackNode* next;
};

/* create a new node */
struct StackNode* newNode( int data ){

	/* allocate memory for new node */
	struct StackNode* Node =
		(struct StackNode*)malloc( sizeof( struct StackNode ));
	Node->data = data;
	Node->next = NULL;
	return Node;
}

int isEmpty( struct StackNode* root ){
	return !root;
}

void push( struct StackNode** root, int data ){
	struct StackNode* Node = newNode(data);
	Node->next = *root;
	*root = Node;
	printf("%d pushed to stack\n", data);
}

int pop( struct StackNode** root ){
	if ( isEmpty(*root) )
		return INT_MIN;
	struct StackNode* temp = *root;
	*root = (*root)->next;

	/* save the value of the node that we want to be droped */
	int popped = temp->data;
	free(temp);

	/* everytimes we dropped a node, we will show the value after dropped */
	return popped;
}

int peek( struct StackNode* root ){
	if ( isEmpty( root ))
		return INT_MIN;
	return root->data;
}

int main(){
	struct StackNode* root = NULL;

	push( &root, 10 );
	push( &root, 11 );
	push( &root, 12 );
	push( &root, 13 );
	push( &root, 14 );

	printf("%d popped from stack\n", pop(&root));
	printf("Top element is %d\n", peek(root));

	return 0;
}
