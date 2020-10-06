#include <stdio.h>
#include <stdlib.h>

struct item {
	int val;
	struct item *next, *prev;
};

void make_list(struct item **first, int value);
void insert_node(struct item *first, struct item **new_first, int value, int pos);
void delete_node(struct item *first, struct item **new_first, int n);
void print(struct item *first);

int main()
{
	struct item *first = NULL;
	int n, value;
	printf("How long will the list be?\n");
	scanf("%d", &n);
	printf("Write the value\n");
	for(int i = 0; i < n; i++) {
		printf("Value %d: ", i);
		scanf("%d", &value);
		make_list(&first, value);
	}
	printf("Her list: \n");
	print(first);
	printf("\n");

	printf("Write inserting value and position: \n");
	scanf("%d %d", &value, &n);
	insert_node(first, &first, value, n);
	printf("List after inserting: \n");
	print(first);
	printf("\n");

	printf("Which node would you like to delete? \n");
	scanf("%d", &n);
	delete_node(first, &first, n);
	printf("List after deleting: \n");
	print(first);
	printf("\n");

	return 0;
}

void make_list(struct item **first, int value)
{
	struct item *tmp;
	tmp = malloc(sizeof(struct item));
	tmp->val = value;
	tmp->next = *first;
	if(*first == NULL)
		tmp->prev = NULL;
	else
		(*first)->prev = tmp;
	*first = tmp;
}

void insert_node(struct item *first, struct item **new_first, int value, int pos)
{
	struct item *tmp = first, *node;
	for(int i = 0; i < pos-1; i++) {
		tmp = tmp->next;
	}
	if(pos != 1) {
		node = malloc(sizeof(struct item));
		node->val = value;
		node->next = tmp;
		node->prev = tmp->prev;
		tmp->prev->next = node;
		tmp->prev = node;
	} else {
		node = malloc(sizeof(struct item));
		node->val = value;
		node->next = first;
		node->prev = NULL;
		*new_first = node; 
	}
}

void delete_node(struct item *first, struct item **new_first, int n)
{
	struct item *current = first, *tmp;
	for(int i = 0; i < n-1; i++)
		current = current->next;
	if(current->prev != NULL && current->next != NULL) {
		tmp = current;
		current->prev->next = current->next;
		current->next->prev = current->prev;
		free(tmp);
	}
	else if(current->prev == NULL) {
		tmp = current;
		current->next->prev = NULL;
		*new_first = current->next;
		free(tmp);
	}
	else if(current->next == NULL) {
		tmp = current;
		current->prev->next = NULL;
		free(tmp);
	}	
}

void print(struct item *first)
{
	struct item *tmp = first;
	while(tmp != NULL) {
		printf("%d", tmp->val);
		tmp = tmp->next;
	}
}
