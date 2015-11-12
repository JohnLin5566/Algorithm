/* A complete working C program to demonstrate deletion in singly
 * linked list */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

/* Given a reference to the head of a list and an int, inserts a
 * new node on the front of the list */

void push ( struct node** head_ref, int new_data ){

	struct node* new_node = ( struct node* ) malloc( sizeof(struct node) );
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Given a reference to the head of a list and a key, deletes the first 
 * occurence of key in linked list */
void deleteNode ( struct node** head_ref, int key ){

	/* store head node */
	struct node* temp = *head_ref, 	*prev;

	printf("*temp     is %d\t\t address is %p\n", *temp, *temp);
	printf("*head_ref is %d\t address is %p\n", *head_ref, *head_ref);
	printf("*prev     is %d\t address is %p\n\n", *prev, *prev);

	/* If head node itself hold the key to be deleted */
	if ( temp != NULL && temp->data == key ){
		*head_ref = temp->next;
		free(temp);
		return;
	}
	
	/* Search for the key to be deleted, keep track of the prev node
	 * as we need to change "prev->next" */
	while ( temp != NULL && temp->data != key ) {
		

		printf("The key is NOT at first node, so we track the next node\n\n");
		/* store temp node at prev node, and try to find the next node, so
		 * temp = temp->next */
		prev = temp;
		temp = temp->next;
		printf("*temp     is %d\t\t address is %p\n", *temp, *temp);
		printf("*head_ref is %d\t address is %p\n", *head_ref, *head_ref);
		printf("*prev     is %d\t\t address is %p\n", *prev, *prev);
		printf("--------------------------------------");
	}

	/* If key was not present in linked list */
	if ( temp == NULL ) return;

	/* Unlink the node from the linked list */
	/* If we find the key at a special node, we need to connect the prev node with
	 * the next node, jump over this temp node */
	prev->next = temp->next;

	/* free the temp node memory */
	free( temp );
}

void printList ( struct node* node ){
	while ( node != NULL ){
		printf(" %d ", node->data );
		node = node->next;
	}
}

int main(){
	/* start with empty list */
	struct node* head = NULL;

	// 7->NULL(head)
	push(&head, 7);
	// 1->7
	push(&head, 1);
	// 0->1->7
	push(&head, 0);
	// 3->0->1->7
	push(&head, 3);
	// 6->3->0->1->7
	push(&head, 6);
	printf("After push 5 integers\n");
	printf("head is %d\t address is %p\n\n", *head, *head);

	puts("Create Linked List: ");
	printList(head);
	printf("\n\n");

	/* delete node that key is 1 */
	deleteNode(&head, 1);

	puts("\nLinked List after Deletion of 1: ");
	printList(head);

	printf("\n\n");

	return 0;
}
