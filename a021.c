/* Understand function insert_node
 * WHY 	new_node->next = prev_node->next;
 * 	prev_node->next = new_node;
 */

#include <stdio.h>
#include <stdlib.h>
/* declaration the struct node */
typedef struct ns{
	int data;
	struct ns* next;
} node;

/* declare others functions */
node * create_node(int);
void insert_node(node* , node*);
void print_lists(node*);
void free_lists(node*);

node* create_node(int data){

	node* n = (node*)malloc( sizeof(node) );
	n->data = data;
	n->next = NULL;
	return n;
}

/* insert node n2 after node n1 */
void insert_node( node* n1, node* n2){
	n2->next = n1->next;
	n1->next = n2;
}

void printNode( node* n ){
	printf("n address is %p\t", n);
	printf("n->data is %d\t", n->data);
	printf("n->next is %p\n", n->next);
}

void print_lists( node* lists){
	node* n = lists;

	/* print the context of the node in order */
	while ( n != NULL){
		printf("n address is %p\t", n);
		printf("n->data is %d\t", n->data);
		printf("n->next is %p\n", n->next);
		n = n->next;
	}
	printf("\n");
}

void free_lists(node* lists){

	/* delete all nodes with recursive method */
	if (lists->next != NULL){
		free_lists(lists->next);
	}
	free(lists);
}

int main(){

	node* lists = create_node(0);
	printNode(lists);
	node* a = create_node(1);
	printNode(a);
	node* b = create_node(2);
	printNode(b);
	node* c = create_node(3);
	printNode(c);
	node* d = create_node(4);
	printNode(d);
	node* e = create_node(5);
	printNode(e);

	printf("\n-----------------\n");

	// "0->5"
	insert_node(lists, e);
	// "0->1"->5
	insert_node(lists, a);
	// 0->"1->2"->5
	insert_node(a, b);
	// 0->"1->3"->2->5
	insert_node(a, c);
	// 0->1->3->2->"5->4"
	insert_node(e, d);

	print_lists(lists);
	free_lists(lists);

	return 0;
}
