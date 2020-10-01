// First, the program asks for the number of input values 
// in order to know how many links in a singly linked list 
// will need to be created for them. Then for each created
// link some value will be added.

#include <stdio.h>
#include <stdlib.h>

struct item {
	int val;
	struct item *next;
};

struct item *first;

void print();
void insert(int n);

int main()
{
	first = NULL;
	int n, value;
	printf("How many numbers? \n");
	scanf("%d", &n);

	for(int k = 0; k < n; k++) {
		printf("Write your number\n");
		scanf("%d", &value);
		insert(value);
		print();
	}

	return 0;
}

void insert(int n)
{	
	struct item *tmp;
	tmp = malloc(sizeof(struct item));
	tmp->val = n;
	tmp->next = first;
	first = tmp;
	return;
}

void print()
{
	struct item *tmp = first;
	printf("Your numbers: ");
	while(tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
	return;
}

