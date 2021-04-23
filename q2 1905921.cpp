//queue using stack
#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int data;
    struct Queue *next;
} Queue;

void enqueue(Queue **top) 
{
    Queue *newnode = (Queue *)malloc(sizeof(Queue));
    printf("Enter the data to be pushed into Queue.\n");
    scanf("%d", &newnode->data);
    newnode->next = *top;
    *top = newnode;
}

int dequeue(Queue **top1)
{
    int dequeueped_value;
    if (*top1 == NULL)
        printf("Queue is Empty.\n");
    else
    {
        if ((*top1)->next == NULL) 
        {
            dequeueped_value = (*top1)->data;
            free(*top1);
            *top1 = NULL;
            return dequeueped_value;
        }
        else
        {
            Queue *newnode, *top2, *temp;
            top2 = NULL;
            while (*top1) 
            {
                temp = *top1;
                newnode = (Queue *)malloc(sizeof(Queue));
                newnode->next = top2;
                newnode->data = (*top1)->data;
                top2 = newnode;
                *top1 = (*top1)->next;
                free(temp);
            }
            dequeueped_value = top2->data;
            top2=top2->next;
            *top1 = NULL;

            while (top2)
            {
                temp = top2;
                newnode = (Queue *)malloc(sizeof(Queue));
                newnode->data = top2->data;
                newnode->next = *top1;
                *top1 = newnode;
                top2 = top2->next;
                free(temp);
            }
        }
    }
    return dequeueped_value;
}

void display(Queue *top)
{
    if (top == NULL)
        printf("sorry,Stack is empty.\n");
    else
    {
        int i = 0;
        while (top)
        {
            printf("value at position  %d is %d.\n", ++i, top->data);
            top = top->next;
        }
    }
}

int main()
{
    Queue *top = NULL;
    int choice;
    while (1)
    {
        printf("What operation do you want me to perform?\n");
        printf("1.Push\n2.dequeue.\n3.Display.\n4.Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&top);
            break;
        case 2:
            dequeue(&top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("sorry,Invalid Choice.\n");
        }
    }
}
