#include <stdio.h>
#include <stdlib.h>

struct item {
	int val;
	struct item *next;
};

struct item *first;

void print(struct item **r);
void insert(int n);

int main()
{
	first = NULL;
	int n, value;
	printf("How many number? \n");
	scanf("%d", &n);

	for(int k = 0; k < n; k++) {
		printf("Write your number\n");
		scanf("%d", &value);
		insert(value);
	}

	return 0;
}

void insert(int n)
{	
	struct item *tmp, **r;
	tmp = malloc(sizeof(struct item));
	tmp->val = n;
	tmp->next = first;
	first = tmp;
	r = &first;
	print(r);
	return;
}

void print(struct item **r)
{
	printf("Your numbers: ");
	while(r != NULL) {
		printf("%d ", (*r)->val);
		if((*r)->next == NULL){
			printf("\n");
			return;
		}
		r = &(*r)->next;
	}
}


