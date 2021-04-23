#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100
char stack[SIZE];
int top=-1;
void push(char item)
{
	if (top==SIZE-1)
	{
		printf("overflow\n");
	}
	else 
	{
		top++;
		stack[top]=item;
	}
}
char pop()
{
	char item;
	if (top==-1)
	{
		printf("underflow\n");
	}
	else 
	{
		item=stack[top];
		top--;
		return (item);
	}
}
int isoperator(char symbol)
{
	if (symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int precedence(char symbol)
{
	if (symbol=='^')
	{
		return 3;
	}
	else if (symbol=='*'|| symbol=='/')
	{
		return 2;
	}
	else if (symbol=='+'|| symbol=='-')
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
int infixtopostfix(char infixexp[],char postfixexp[])
{
	int i=0,j=0;
	char item;
	char x;
	push('(');
	strcat(infixexp,")");
	item=infixexp[i];
while(item != '\0')        /* run loop till end of infix expression */
	{
	//	item=infixexp[i];
		if (item=='(')
		{
			push(item);
		}
		else if(item>='A'&& item<='Z' || item>='a'  && item<='z')
		{
			postfixexp[j]=item;
			j++;
			
		}
		else if (isoperator(item)==1)
		{
			x=pop();
			while (isoperator(x)==1 && precedence(x)>precedence(item))
			{
				postfixexp[j]=x;
				j++;
				x=pop();
			}
			push(x);
			push(item);
		}
		else if (item==')')
		{
			x=pop();
			while (x!='(')
			{
				postfixexp[j]=x;
				j++;
				x=pop();
			}
		}
		else 
		{
			printf("invalid expression\n");
			getchar();
			exit(1);
			
		}
		i++;
		item=infixexp[i];
	}
}
int main()
{
	char infix[SIZE], postfix[SIZE];         /* declare infix string and postfix string */

	/* why we asked the user to enter infix expression
	* in parentheses ( )
	* What changes are required in porgram to
	* get rid of this restriction since it is not
	* in algorithm
	* */
	printf("ASSUMPTION: The infix expression contains single letter variables and single digit constants only.\n");
	printf("\nEnter Infix expression : ");
	gets(infix);

	infixtopostfix(infix,postfix);                   /* call to convert */
	printf("Postfix Expression: ");
	puts(postfix);                     /* print postfix expression */

	return 0;
}
