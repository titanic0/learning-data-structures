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
	node = malloc(sizeof(struct item));
	node->val = value;
	if(tmp->next != NULL && tmp->prev != NULL) { // if we are not adding 
		node->next = tmp;		     // to the beginning or to the end
		node->prev = tmp->prev;
		tmp->prev->next = node;
		tmp->prev = node;
	} 
	else if(tmp->next != NULL && tmp->prev == NULL) { // if we are adding to the beginning
		node->next = tmp;
		node->prev = NULL;
		*new_first = node; 
	}
	else if(tmp->next == NULL && tmp->prev !=NULL) { // if we are adding to the end
		node->next = NULL;
		node->prev = tmp;
		node->prev->next = node;
	}
}

void delete_node(struct item *first, struct item **new_first, int n)
{
	struct item *current = first, *tmp;
	for(int i = 0; i < n-1; i++)
		current = current->next;
	tmp = current;
	if(current->prev != NULL && current->next != NULL) { // if the element to be removed
		current->prev->next = current->next;	     // is not at the beginning
		current->next->prev = current->prev;	     // or at the end
		free(tmp);
	}
	else if(current->prev == NULL) {		     // if the element to be removed
		current->next->prev = NULL;		     // at the beginning
		*new_first = current->next;
		free(tmp);
	}
	else if(current->next == NULL) {		     // if the element to be removed
		current->prev->next = NULL;		     // at the end
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
