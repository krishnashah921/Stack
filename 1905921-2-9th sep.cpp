#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct node *top=NULL;
void create(int data1);
void display();
int pop();
int main()
{
	int ch,data1;
//	struct node *top=NULL;
	while (1)
	{
		printf("1.create\n");
		printf("2.display\n");
		printf("3.pop\n");
		printf("4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
	        printf("enter the data you want to input\n");
	        scanf("%d",&data1);
			create(data1);
			break;
			case 2:
			display();
			break;
			case 3:
			pop();
			break;
			case 4:
			exit(1);
			break;
			default:
			printf("wrong choice\n");
		}
	}
	return 0;
}
void create(int data1)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof (struct node));
	newnode->data=data1;
	newnode->next=top;
	top=newnode;
}
void display()
{
	struct node *temp;
	if (top==NULL)
	{
	return;
	}
	else 
	{
	int c=pop();
	display();
	printf("%d\t",c);
	create(c);
	}
}
int  pop()
{
	struct node *temp=top;
	if (top==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		int x=temp->data;
		top=temp->next;
		return x;
	}
}
