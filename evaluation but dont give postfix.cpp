#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int arr[100] ;
    int top ;
};
void push(struct stack *s,int a)
{
    if((*s).top==100-1)
    {
        printf("overflow\n") ;
        return ;
    }
    (*s).top++ ;
    (*s).arr[((*s).top)]=a ;
}
int pop(struct stack *s)
{
    if((*s).top==-1)
    {
        printf("underflow\n") ;
        return -1 ;
    }
    int z=(*s).arr[(*s).top] ;
    (*s).top-- ;
    return z ;
}
int main(void)
{
  struct stack st ;
    st.top=-1 ;
   int n ;
   printf("Enter length of expression\n") ;
   scanf("%d",&n) ;
   char *s ;
   s=(char *)malloc((n+2)*sizeof(char)) ;
   printf("enter expression\n") ;
   scanf(" %s",s) ;
   s[n]=')' ;
   s[n+1]='\0' ;
  printf("expression is %s\n\n ",s) ;
  int x=0,a,b ;
  while(s[x]!=')')
  {
    if(s[x]=='+')
    {
      a=pop(&st) ;
      b=pop(&st) ;
      push(&st,a+b) ;
      x++ ;
      continue ;
    }
    if(s[x]=='-')
    {
      a=pop(&st) ;
      b=pop(&st) ;
      push(&st,b-a) ;
      x++ ;
      continue ;
    }
    if(s[x]=='*')
    {
      a=pop(&st) ;
      b=pop(&st) ;
      push(&st,b*a) ;
      x++ ;
      continue ;
    }
    if(s[x]=='/')
    {
      a=pop(&st) ;
      b=pop(&st) ;
      push(&st,b/a) ;
      x++ ;
      continue ;
    }
    push(&st,(int)s[x]-48) ;
    x++ ;
  }
  printf("Result= %d\n",pop(&st)) ;
    return 0 ;
}
