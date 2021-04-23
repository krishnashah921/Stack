#include<stdio.h>
#define max 100
int s[max],top=-1;
void push(int element);
int pop();
void display();
void sorting();
void insert(int x);
int main()
{
	int data,ch=1,s=1;
	while (s==1)
	{
	printf("enter the choice\n");
	printf("1.push\n");
	printf("2.sorting\n");
	printf("3.display\n");
	printf("4.stop\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printf("enter the data\n");
	    scanf("%d",&data);
	    push(data);
	    break;
	    case 2:
	    //pop();
	    sorting();
	    display();
	    printf("\n");
	    break;
	    case 3:
	    display();
	    printf("\n");
	    break;
	    case 4:
	    //exit(1);
	    s=0;
	    break;
	    default:
	    	printf("wrong choice\n");
	    break;
	}
	}
	return 0;
}
void push(int element)
{
	if (top>max-1)
	{
		printf("overflow");
		return;
	}
	else 
	{
		top=top+1;
		s[top]=element;
	}
}
int  pop()
{
	int value;
	if (top== -1)
	{
		printf("underflow");
	}
	else 
	{
		value=s[top];
		top=top-1;
		return value;
	}
}
void display()
{
	int i;
	if (top==-1)
	{
		return ;
	}
	i=pop();
	display();
	printf("%d\t",i);
	push(i);
	
}
void sorting()
{
	if (top!=-1)
	{
		int x=pop();
		sorting();
		insert(x);
	}
}
void insert(int x)
{
	if (top==-1||x>s[top])
	{
		push(x);
		return;
	}
	int t=pop();
	insert(x);
	push(t);
}
