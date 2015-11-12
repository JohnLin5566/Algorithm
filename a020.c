/* A complete working C program to demonstrate all insertion methods */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

/* Given a reference to the head of a list and an int, inserts a new node in 
 * the front of the list */
void push(struct node** head_ref, int new_data){

	struct node* new_node = (struct node*)malloc( sizeof(struct node) );
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after a given prev_node */
void insertAfter( struct node* prev_node, int new_data ){
	
	if ( prev_node == NULL ){
		printf("the given previous node cannnot be NULL\n");
	}

	struct node* new_node = (struct node*)malloc( sizeof(struct node) );
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

/* Given a reference to the head of a list and an int, append a new node at the end */
void append( struct node** head_ref, int new_data ){

	struct node* new_node = (struct node*) malloc( sizeof(struct node) );
	struct node* last = *head_ref;

	new_node->data = new_data;

	/* This new node is going to be the last node, so make next of it as NULL */
	new_node->next = NULL;

	if ( *head_ref == NULL){
		*head_ref = new_node;
		return;
	}

	while ( last->next != NULL )
		last = last->next;

	last->next = new_node;
	return ;
}

void printList( struct node* node ){
	
	while ( node != NULL){
		printf(" %d", node->data );
		node = node->next;
	}
	printf("\n");
}

int main(){
	
	/* start with the empty list */
	struct node* head = NULL;
	printf("At the first declaration, struct node* head = NULL;\n");
	printf("head = NULL is %p \n", head);


	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);

	/* Insert 8, after 7. And 7 at head->next */
	insertAfter(head->next, 4);

	printList(head);
	return 0;
}
