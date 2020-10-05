#include <stdio.h>
#include <stdlib.h>

struct item {
	int val;
	struct item *next;
};

void Insert(struct item **add_values, 
	    struct item *first, int value, int node);
void Print(struct item *first);

int main()
{
	struct item *first = NULL;
	Insert(&first, first, 2, 1);
	Insert(&first, first, 3, 2);
	Insert(&first, first, 4, 1);
	Insert(&first, first, 5, 2);
	Insert(&first, first, 6, 3);
	Insert(&first, first, 10, 1);
	Insert(&first, first, 6, 3);
	Insert(&first, first, 100, 2);
	Print(first);

	return 0;
}

void Insert(struct item **add_values, 
	    struct item *first, int value, int node)
{
	struct item **check_value = add_values;
	struct item *tmp;
	int k = 0;
	for(int i = 0; i < node-1; i++) {
		if((*check_value)->next != NULL) {
			check_value = &(*check_value)->next;
		}
		k++;
	}
	tmp = malloc(sizeof(struct item));
	tmp->val = value;
	if(*add_values == NULL) {
		*add_values = tmp;
		tmp->next = NULL;
		return;
	}
	else if(k == 0) { 			// insert to the beginning
		tmp->next = *check_value;
		*check_value = tmp;
		return;
	}
	else if(k == 1) {			// insert to the second position
		tmp->next = first->next;
		first->next = tmp;
		return;
	}
	tmp->next = (*check_value)->next;	// insert to the rest of the list
	(*check_value)->next = tmp;
}

void Print(struct item *first)
{
	struct item *tmp = first;
	while(tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
}

