/*

Author : Rahul Darekar
Date : 03-08-2023
Desc : Implementation of linkedlist using c structures and pointers

*/

/*
* Adding node in list
* Deleting node in list
* Adding in center of list
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PRINT 'p'
#define NODE 'n'
#define DELETE 'd'
#define EXIT 'e'
#define TRACE { printf("Linked list is initiated...\nAt moment %s %s \n",__DATE__ , __TIME__); }



// Struct data is independent of linked list operations. It only handle data in flexible way.
struct n_data {
	int age; // 4 bytes
	char* n;
};
typedef struct n_data list_node_data;


/*

node struct is actuall node of linked list which hold pointer to next node of list as well as pointer to n_data struct.
Struct which represent node of linked list.

*/
typedef struct node list_node;

struct node {
	list_node_data *node_data;
	struct node *next;
};


struct list {
	struct node* list_init; // Initially NULL;
	int  list_len; // Initially declare as 0;
	short a;
	char h;
};  

struct list* _list; // Declare global list pointer


void print_list() {
	// Print nodes of list through
	list_node* current_node;
	current_node = _list -> list_init;
	printf("\n-----------------------\n");
	while(current_node != NULL) {
		// Traverse the list
		printf("node %d -> " , current_node -> node_data -> age);
		current_node = current_node -> next;
	}
	printf("\n-----------------------\n\n");
}
	
/*

Add node
Delete node
Add in middle
Search for node

*/

void add_node(list_node *node) {
	
	// Operation will execute on list location (pointer);
	
	list_node* currentnode = _list -> list_init;
	if(currentnode == NULL) {
		// Head node of List
		_list -> list_init = node;
		_list -> list_len++;
	} else {
		node -> next = currentnode;
		_list -> list_init = node;
		_list -> list_len++;
	}
}


void delete_node(void) {
	int n;
	printf("Enter node value you want to delete : ");
	scanf("%d",&n);
	list_node* curr = _list -> list_init; // starting pointer of list
	list_node* pre = NULL;
	while(curr != NULL) {
		if(n == curr -> node_data -> age) {
			
			// found the node to be delete by value
			// attaching addr of next node pointer to previous node next poiter
			
			if(pre == NULL) {
				// first node of list is matched and need to delete
				_list -> list_init = curr -> next;
			} else {
				pre -> next = curr -> next;
				free(curr -> node_data);
				free(curr);
			}
			_list -> list_len--;
			break;
		}
		pre = curr;
		curr = curr -> next;
	}
}

// node1 -> node2 -> node3

list_node* create_list_node(list_node_data *n) {
	/* 
	   Initiate new node in list 
	   With use of malloc 
	*/
	list_node *node = malloc(sizeof(list_node));	
	node -> node_data = n;
	node -> next = NULL;
	return node;
}

void add_node_process(void) {
	int i_age;
	printf("Enter node value you want to create : ");
	scanf("%d",&i_age);
	getchar();
	list_node_data *n = malloc(sizeof(list_node_data));
	n -> age = i_age;
	n -> n = NULL;
	list_node *node = create_list_node(n); // Return pointer to newly created list node 
	add_node(node);
}


// For test purpose of add node in list

void add_node_process_test(int i_age) {
	// int i_age;
	list_node_data *n = malloc(sizeof(list_node_data));
	n -> age = i_age;
	n -> n = NULL;
	list_node *node = create_list_node(n); // Return pointer to newly created list node 
	add_node(node);
}

int main() {
	_list = malloc(sizeof(*_list));
	_list -> list_init = NULL;
	_list -> list_len = 0;
	TRACE
	clock_t t;
    t = clock();
	for(int i = 0;i < 100000000; i++) {
		add_node_process_test(i);
	};
	t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Time took %f seconds to execute \n", time_taken);
	 // return 0;
	while (1) {
		char cmd;
		printf("\nType operatio to perform : ");
		scanf("%c",&cmd);
		fflush(stdin);
		switch(cmd) {
			case PRINT:
					printf("Main list is printed below...\n");
					print_list();
					break;
			case NODE:
					add_node_process();
					printf("Node added successfully.\n");
					break;
			case DELETE:
					delete_node();
					printf("Node delete successfully.\n");
					break;
			case EXIT:
					printf("Programe exited successfully.\n");
					exit(0);
			default:
					printf("Command not found please check h for help.\n");
					break;
		};
		
		printf("Length of list is %d\n" , _list -> list_len);
	}
	
	return 0;
}

/*

int main() {
	list *main_list;// Declared list pointer variable of type struct node.
	printf("Main list pointer or location is %p\n", main_list);
	
	list_node n_1;
	printf("Size of list node of list is %lu\n",sizeof(n_1));
	struct n_data ne;
	char *r = "rahul";
	ne.age = 23;
	ne.fn = r;
	printf("Size of list node data is %lu\n",sizeof(ne));
	printf("n1 pointer is %p",&ne);
	n_1.node_data = &ne;
	
	// Add node function calling
	add_node(main_list , &n_1);
	print_list(main_list);
	return 0;
}

*/