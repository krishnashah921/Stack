#include<stdio.h>
#include<stdlib.h>
#define max 100
struct stack{
	int top;
	int st[100];
};
void push(struct stack *s,int a);
int pop(struct stack *s);
void display(struct stack *s);
int main()
{
	struct stack *s1=(struct stack*)malloc(sizeof(struct stack));
	s1->top=-1;
	int ch;
	printf("1.push\n");
	printf("2.pop\n");
	printf("3.display\n");
	printf("4.exit\n");
	while (1)
	{
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
				int data;
				printf("enter the data to be entered\n");
				scanf("%d",&data);
				push(s1,data);
				break;
			case 2:
				pop(s1);
				break;
			case 3:
				display(s1);
				break;
			case 4:
				exit(1);
			break;
			default:
			    printf("wrong choice\n");
			    break;
		}
	}
	return 0;
}
void push(struct stack *s,int a)
{
	if (s->top==max-1)
	{
		printf("overflow\n");
	}
	else 
	{
		s->top++;
		s->st[s->top]=a;
	}
	
}
int pop(struct stack *s)
{
	if (s->top==-1)
	{
		printf("underflow\n");
	}
	else
	{
		int re=s->st[s->top];
		s->top--;
		return re;
	}
}
void display(struct stack *s)
{
	if (s->top==-1)
	{
		return ;
	}
	int z=pop(s);
	display(s);
	printf("%d\t",z);
	push(s,z);
}
