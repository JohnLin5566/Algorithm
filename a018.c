/* Linked list practice, output the linked list with while */
#include<stdio.h>
#include<stdlib.h>

typedef struct list{
	unsigned int value;
	struct list *next;
} item;

int main(){

	item *head, *curr;
	int i ;

	head = NULL;

	for ( i=1; i<=10; i++ ){
		curr = (item *)malloc( sizeof(item) );
		printf("sizeof curr %d\t", (int) sizeof(curr) );
		printf("curr is %p \t", curr );
		curr->value = i;
		printf("curr->value is %d \t", curr->value );
		curr->next = head;
		printf("curr->next is %p \n", curr->next );
		head = curr;
		printf("head = curr is %p \n", head );
	}

	curr = head;
	printf("curr = head is %p \n", curr );

	printf("\n--------------------------------------\n");

	while ( curr ){
		printf("curr->value is %d \n", curr->value);
		curr = curr->next;
	}

	printf("\nsizeof curr is %d\n", (int) sizeof(curr));
	printf("\nsizeof head is %d\n", (int) sizeof(head));

	return 0;
}
