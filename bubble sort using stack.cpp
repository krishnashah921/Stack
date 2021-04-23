#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int st1[MAX];int st2[MAX];
int top1=-1;int top2=-1;
void push(int st[],int *top,int element);
int pop(int st[],int *top);
void sort(int st1[],int st2[],int *top1,int *top2);
void display(int st[],int *top);
int main()
{
    int arr[MAX]={5,3,1,4,2,};
    while(1)
    {
        int ch;
        printf("Enter your choice\n");
        printf("1.Push elements in stack 1\n");
        printf("2.Insert elements in stack 2\n");
        printf("3.Display elements of stack 1\n");
        printf("4.Display elements of stack 2\n");
        printf("5.Exit\n");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
        case 1:{
            int i;
            for(i=0;i<MAX;i++)
            {
                push(st1,&top1,arr[i]);
                printf("The element pushed in the stack is %d\n",arr[i]);
            }
            break;
            }
        case 2:sort(st1,st2,&top1,&top2);
        break;
        case 3:display(st1,&top1);
        break;
        case 4:display(st2,&top2);
        break;
        case 5: exit(1);
        break;
        default: printf("Invalid input\n");
        break;
        }
    }
    return 0;
}
void push(int st[],int *top,int element)
{
    if((*top)==MAX-1)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        (*top)++;
        st[*top]=element;
    }
}
int pop(int st[],int *top)
{
    int e;
    if((*top)==-1)
    printf("Stack is underflow\n");
    else
    {
        e=st[*top];
        top--;
    }
    return e;
}
void sort(int st1[],int st2[],int *top1,int *top2)
{
                int x,y;
                if((*top1)!=-1)
                {
                x=pop(st1,&(*top1));
                insert(st2,&(*top2),x);
                }
}
void insert(int st2[],int *top2,int a)
{
        int y;
        if((*top2)==-1||st2[*top2]<a)
        {
            push(st2,&top2,a);
        }
        else
        {
            y=pop(st2,&(*top2));
            insert(st2,&(*top2),a);
            push(st2,&(*top2),y);
        }
}
void display(int st[],int *top)
{
    int i;
    for(i=0;i<=(*top);i++)
    {
        printf("%d\n",st[i]);
    }
    printf("\n");
}
