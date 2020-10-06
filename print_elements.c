#include <stdio.h>
#include <stdlib.h>

struct item {
	int val;
	struct item *next;
};

void make_list(struct item **first, int val);
void print(struct item *first);
void recursive_print(struct item *first);
void reverse_list(struct item **first, struct item *prev,
		  struct item *current, struct item *next);

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
		printf("\n");
		make_list(&first, value);
	}
	
	printf("Let's print your list: \n");
	print(first);
	printf("\n");
	printf("Let's print reverse your list: \n");
	recursive_print(first);
	printf("\n");
	printf("Let's write the values in reverse order: \n");
	reverse_list(&first, NULL, first, first->next);
	print(first);
	printf("\n");

	return 0;
}

void make_list(struct item **first, int val)
{
	struct item *tmp;
	tmp = malloc(sizeof(struct item));
	tmp->val = val;
	tmp->next = *first;
	*first = tmp;
}

void print(struct item *first)
{
	if(first == NULL)
		return;
	printf("%d ", first->val);
	print(first->next);
}

void recursive_print(struct item *first)
{
	if(first == NULL)
		return;
	recursive_print(first->next);
	printf("%d ", first->val);
}

void reverse_list(struct item **first, struct item *prev,
                  struct item *current, struct item *next)
{
	if(current == NULL)
		return;
	next = current->next;
	current->next = prev;
	prev = current;
	current = next;
	*first = prev;
	reverse_list(first, prev, current, next);
}
