#include <stdio.h>
#include <stdlib.h>
#define max 100

struct stack
{
    int top;
    int st[100];
};

void push(struct stack *s, int a)
{
    if(s->top == max-1)
        printf("Overflow");
    else
    {
        s->top++;
        s->st[s->top] = a;
    }
}

int pop(struct stack *s)
{
    int z;
    if(s->top == -1)
        return 0;
    z = s->st[s->top];
    s->top--;
    return z;
}

void display(struct stack *s)
{
    int z;
    if(s->top == -1)
        return ;
    z = pop(s);
    display(s);
    printf("# %d #\n", z);
    push(s, z);
}

int main()
{

    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
    s1->top = -1;

    int l=1, choice, n, n1;
    printf("\n----------- Menu Linked List Stack -----------\n");
    printf("1. Push/Insert a value in the stack\n");
    printf("2. Delete the top element of the stack\n");
    printf("3. Display the stack same order (using recursion)\n");

    while(l = 1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the data to be kept in stack: ");
            scanf("%d", &n1);
            push(s1, n1);
            break;
        case 2:
            n = pop(s1);
            printf("The deleted element is: %d", n);
            break;
        case 3:
            display(s1);
            break;
        case 0:
            exit(0);
            break;
        }
    }
}
