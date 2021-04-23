#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define MAXPOSTFIXSIZE 100
int stack[MAXSIZE];
int top=-1;
void push(int item)
{
	if (top==MAXSIZE-1)
	{
		printf("overflow\n");
	}
	else 
	{
		top++;
		stack[top]=item;
	}
}
int pop()
{
	if (top==-1)
	{
		printf("underflow");
	}
	else 
	{
		int ret=stack[top];
		top--;
		return ret;
	}
}
void evaluatepostfix(char postfix[])
{
	int i;
	char ch;
	int val,a,b;
	for (i=0;postfix[i]!=')';i++)
	{
		ch=postfix[i];
		if (ch>='0' && ch<='9')
		{
			push(ch-'0');
		}
		else if (ch=='+'|| ch=='-'|| ch=='*'|| ch=='/')
		{
			a=pop();
			b=pop();
			switch (ch)
			{
				case '+':
					val=b+a;
					break;
				case '-':
					val=b-a;
					break;
				case '*':
					val=b*a;
					break;
				case '/':
					val=b/a;
					break;
			}
			push(val);
		}
	}
	printf("\n%d\n",pop());
}
int main()
{
	char postfix[MAXPOSTFIXSIZE];
	printf("ASSUMPTION: There are only four operators(*, /, +, -) in an expression and operand is single digit only.\n");
    printf(" \nEnter postfix expression,\npress right parenthesis ')' for end expression : \n");
     for (int i = 0; i <= MAXPOSTFIXSIZE - 1; i++) {
        scanf("%c", &postfix[i]);

        if (postfix[i] == ')') 
        {
            break;
        }
    }
    evaluatepostfix(postfix);
    return 0;
}

