// First, the program asks for the number of input values 
// in order to know how many links in a singly linked list 
// will need to be created for them. Then for each created
// link some value will be added.
// Then you can add new node at nth position.

#include <stdio.h>
#include <stdlib.h>

struct item {
	int val;
	struct item *next;
};

void print(struct item *first);
void insert(struct item **check_values, int n);
void new_node_insert(struct item **check_node, int count, int n);
void print_all(struct item *first);

int main()
{
	struct item *first = NULL;
	int n, value, new_node;
	printf("How many numbers? \n");
	scanf("%d", &n);

	for(int k = 0; k < n; k++) {
		printf("Write your number\n");
		scanf("%d", &value);
		insert(&first, value);
		print(first);
	}

	printf("In which node do you want to insert the new value?\n");
	scanf("%d", &new_node);
	printf("Write your value for this node\n");
	scanf("%d", &value);
	new_node_insert(&first, value, new_node);
	print_all(first);

	return 0;
}

void insert(struct item **check_values, int n)
{	
	struct item *tmp;
	tmp = malloc(sizeof(struct item));
	tmp->val = n;
	tmp->next = *check_values;
	*check_values = tmp;
}

void print(struct item *first)
{
	struct item *tmp = first;
	printf("Your numbers: ");
	while(tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
}

void new_node_insert(struct item **check_node, int count, int n)
{
	struct item *tmp;
	struct item **new_node = check_node;
	for(int i = 0; i<n-1; i++) {
		new_node = &(*new_node)->next;
	}
	tmp = malloc(sizeof(struct item));
	tmp->val = count;
	tmp->next = (*new_node)->next;
	(*new_node)->next = tmp;
}

void print_all(struct item *first)
{
	struct item *tmp = first;
	while(tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
}

