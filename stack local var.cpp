#include<stdio.h>
void push(int arr[],int element,int *top);
void display(int arr[],int *top);
void pop(int arr[],int *top);
int main()
{
	int top=-1;
	int ch=1,data,a[5];
	int *arr=a;
	while(ch==1)
	{
		printf("enter the data\n");
		scanf("%d",&data);
		push(arr,data,&top);
		printf("do you want to input more(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\n");
	display(arr,&top);
	ch=1;
	printf("\n");
	while(ch==1)
	{
		pop(arr,&top);
		printf("do you want to input more(0/1)\n");
		scanf("%d",&ch);
	}
	printf("\n");
	display(arr,&top);
	return 0;
}
void push(int arr[],int element,int *top)
{
	if (*top==4)
	{
		printf("overflow\n");
		return;
	}
	else 
	{
		*top=*top+1;
		arr[*top]=element;
	}
}
void display(int arr[],int *top)
{
	int i;
	for (i=*top;i>=0;i--)
	{
		printf("%d\n",arr[i]);
	}
}
void pop(int arr[],int *top)
{
	if (*top==-1)
	{
		printf("underflow");
	}
	else 
	{
		*top=*top-1;
	}
}
