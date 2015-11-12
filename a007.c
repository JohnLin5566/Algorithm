/* Linked list */

/* struct declaration:
	struct node{
		Type data;
		Node *next;
	}
 */

/* this list have two opeartion, remove and insert
	void insert(Node *n1, Node *n2 ){
		//insert n2 after n1
 		n2->next = n1 ->next;
 		n1->next = n2;
	}

 	void remove(Node *n1){
 		n1->next = n1->next->next;
 	}

 */

#include<stdio.h>
#include<stdlib.h>

/* declaration the struct node */
typedef struct ns{
	int data;
	struct ns* next;
} node;

node* create_node(int data){
	node* n = (node*)malloc( sizeof(node) );

	n->data = data;
	n->next = NULL;
	return 0;
};

/* insert node n2 after node n1 */
void insert_node( node* n1, node* n2){
	n2->next = n1->next;
	n1->next = n2;
}

void print_lists( node* lists){
	node* n = lists;

	/* print the context of the node in order */
	while ( n != NULL){
		printf("%d", n->data);
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
	node* a = create_node(1);
	node* b = create_node(2);
	node* c = create_node(3);
	node* d = create_node(4);
	node* e = create_node(5);

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
