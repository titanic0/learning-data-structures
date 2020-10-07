#include <stdio.h>
#include <stdlib.h>

struct item {
	int val;
	struct item *next, *prev;
};

struct ch {
	char sym;
	struct ch *next;
};

void print(struct item *first, struct ch *first_ch)
{
	if(first_ch != NULL) {				// output linked list with numeric values
		struct ch *tmp = first_ch;
		while(tmp != NULL) {
			printf("%c", tmp->sym);
			tmp = tmp->next;
		}
		printf("\n");
	} else {					// output linked list with char values
		struct item *tmp = first;
		while(tmp != NULL) {
			printf("%d", tmp->val);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

void pop(struct item **first)				// getting top node to the linked list
{
	struct item *tmp;
	tmp = *first;
	if(first == NULL)
		return;
	*first = (*first)->next;
	free(tmp);
}	

void push(struct item **first, int val)			// adding a new node to the linked list
{
	struct item *tmp;
	tmp = malloc(sizeof(struct item));
	tmp->val = val;
	tmp->next = *first;
	if(*first != NULL)
		(*first)->prev = tmp;
	else
		tmp->prev = NULL;
	*first = tmp;
}

struct ch *reverse(char *first, int n)			// reversing a string
{
	struct ch *tmp, *begin = NULL;
	for(int i = 0; i < n; i++) {
		tmp = malloc(sizeof(struct ch));
		tmp->sym = first[i];
		tmp->next = begin;
		begin = tmp;
	}
	return begin;
}

int main()
{
        struct item *first = NULL;
        int n, val;
        printf("How long list would be?\n");
        scanf("%d", &n);
        printf("Write the values: ");
        for(int i = 0; i < n; i++) {
                printf("\n");
                printf("%d: ", i);
                scanf("%d", &val);
                push(&first, val);
        }

	struct ch *p;
	char C[11] = "";
	printf("Input: ");
	scanf("%10s", C);
	printf("\n");

	p = reverse(C, sizeof(C));
	printf("Output: ");
	print(NULL, p);
	printf("\n");

	while(p != NULL) {
		struct ch *tmp;
		tmp = p;
		p = p->next;
		free(tmp);
	}

        return 0;
}

