#include <stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x)
{
	if(top == MAX_SIZE -1) {
		printf("Error: stack overflow\n");
		return;
	}
	A[++top] = x;
}

void Pop()
{
	if(top == -1) {
		printf("No element to pop\n");
		return;
	}
	top--;
}

void print()
{
	for(int i = 0; i<=top; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	Push(2);print();
	Push(3);print();
	Pop();print();
	Push(5);print();
	Pop();print();
	Pop();print();

	return 0;
}
