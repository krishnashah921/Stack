#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 80
struct stack{
	int top;
	int item[MAX];
};
void push(struct stack*,int);
int pop(struct stack*);
void display(struct stack*);
int isdigit(char);
int eval(char[]);
int oper(char,int,int);
void push(struct stack *s,int x)
{
	if (s->top==MAX-1)
	{
		printf("underflow\n");
	}
	else 
	{
		s->top++:
		s->item[s->top]=x;
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
		int ret=s->item[s->top];
		s->top--;
		return ret;
	}
}
void display(struct stack *s)
{
	int ctr=s->top;
	while (ctr!=-1)
	{
		printf("%d\t",s->item[ctr--]);
	}
}
int isdigit(char ch)
{
	return (ch>='0' && ch<='9');
}
int oper(char c,int oper1,int oper2)
{
	switch (c)
	{
		case '+':
			return (oper1+oper2);
		case '-':
			return (oper1-oper2);
		case '*':
			return (oper1*oper2);
		case '/':
			return (oper1/oper2);
		case '^':
			return (pow(oper1,oper2));
		default :
			return 0;
    }
}
int eval(char str[])
{
	char c;
	int oper1,oper2,val;
	struct stack *s;
	s->top=-1;
	int i;
	for (i=0;(c=str[i]!=')');i++)
	{
		if (isdigit(c))
		{
			push(&s,(int)(c-'0'));
		}
		else 
		{
			oper2=pop(&s);
			oper1=pop(&s);
			val=oper(c,oper1,oper2);
			push(&s,val);
		}
		return pop(&s);
	}
}
int main()
{
	char str[MAX];
	int i,j,k;
	char temp;
	printf("enter the string of prefix\n");
	for (i=0;(str[i]=getchar())!='n';i++)
	{
		str[i]=')';
		k=i;
		printf("enter the prefix expression\n");
		for (i=0,j=k-1;i<=j;i++;j--)
		{
			
		}
	}
}
