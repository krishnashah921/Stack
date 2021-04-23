#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
void create(struct node **top);
void display(struct node **top);
struct node *pop(struct node **top);
int main()
{
	int ch=1;
	struct node *top=NULL;
	while (ch==1)
	{
		create(&top);
		printf("do you want to enter more data(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\n");
	display(&top);
	ch=1;
	while (ch==1)
	{
		pop(&top);
		printf("do you want to enter more data(0/1)\n");
		scanf("%d",&ch);
	}
	display(&top);
	return 0;
}
void create(struct node **top)
{
	struct node *newnode;
	int data1;
	printf("enter the data you want to input\n");
	scanf("%d",&data1);
	newnode=(struct node*)malloc(sizeof (struct node));
	newnode->data=data1;
	newnode->next=*top;
	*top=newnode;
}
void display(struct node **top)
{
	struct node *temp;
	if (*top==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		temp=*top;
		while (temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
struct node *pop(struct node **top)
{
	struct node *temp=*top;
	if (*top==NULL)
	{
		printf("no record\n");
	}
	else 
	{
		*top=temp->next;
	}
}
