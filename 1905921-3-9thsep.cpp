#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 5

typedef int boolean;
#define TRUE 1
#define FALSE 0

struct arrayStack {
	int stk[MAX_STACK_SIZE];
	int top;
};
typedef struct arrayStack arrayStack;
void push(arrayStack *stack, int element);
int pop(arrayStack *stack);
boolean isEmpty(arrayStack *stack);
void display(arrayStack *stack);


int main() {
	int element, choice;
	arrayStack stack;
	arrayStack *stackptr = &stack;
	stack.top = -1;
	while(1) {
		printf("Choose the operation you want to perform\n");
		printf("1. push \n2. pop \n3. display \n4. exit\n");
		printf("Enter the choice\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter the element you wish to push\n");
				scanf("%d", &element);
				push(stackptr, element);
				break;
			case 2:
				printf("poped element is %d\n", pop(stackptr));
				break;
			case 3:
				display(stackptr);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Invalid input\n");
		}
	}
	return EXIT_SUCCESS;
}

void push(arrayStack *stack, int n) {
	if(stack->top == MAX_STACK_SIZE - 1) {
		printf("Warning: Stack is full, You can't add'\n");
		return;
	} else {
		stack->stk[++stack->top] = n;
	}
}

int pop(arrayStack *stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty\n");
		return NULL;
	} else {
		int temp;
		temp = stack->stk[stack->top--];
		return temp;
	}
}
int isEmpty(arrayStack *stack) {
	if (stack->top == -1)
		return TRUE;
	else
		return FALSE;
}

void display(arrayStack *stack) {
	int i = stack->top;
	for (; i >= 0; --i)
		printf("%d\t", stack->stk[i]);
	printf("\n");
}
