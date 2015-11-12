#include<stdio.h>
#include<stdlib.h>

typedef struct ns{
    int data;
    struct ns* next;
} node;

node* create_node(int data){
    node* n = (node*) malloc ( sizeof(node) );
    n->data = data;
    n->next = NULL;
}
void insert_node(node*, node*){
    n2-> next = n1->next;
    n1-> next = n2;
}
void remove_node(node* n1){
    n1->next = n1->next->next;
}
void print_lists(node* lists){
    node* n = lists;
    while ( n != NULL){
    		printf("%d", n->data);
    		n = n->next;
	}
    printf("\n");
}
void free_lists(node*)
    if (lists->next != NULL){
        free_lists(lists->next);
    }
    free(lists);
}
