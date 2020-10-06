#include <stdio.h>
#include <stdlib.h>

struct item {
	int val;
	struct item *next;
};

void make_list(struct item **first, int n);
void reverse(struct item **first, int n);
void print(struct item *first);

int main()
{
	struct item *first = NULL;
	int n;
	printf("How long list would you like?\n");
	scanf("%d", &n);
	make_list(&first, n);
	printf("Let's reverse it!\n");
	reverse(&first, n); 
	print(first);

	return 0;
}

void make_list(struct item **first, int n)
{
	struct item *tmp;
	for(int i = 0; i < n; i++) {
		tmp = malloc(sizeof(struct item));
		tmp->val = i;
		tmp->next = *first;
		*first = tmp;
	}
}

void reverse(struct item **first, int n)
{
	struct item *current, *prev, *next;
	current = *first;
	prev = NULL;
	while(current != NULL)  {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*first = prev;

	return;
}

void print(struct item *first)
{
	struct item *tmp = first;
	while(tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
}

