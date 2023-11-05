#include <stdio.h>
#include <stdlib.h>
//sri rama jayam

int stack[2];
int top=-1;

int push(int a)
{
  top=top+1;
  stack[top]=a;
}
int pop()
{
    int top_value=stack[top];
    top=top-1;
    return top_value;
}



int main()
{   int num1,num2;
    printf("enter num1: ");
    scanf("%d",&num1);

    printf("enter num2: ");
    scanf("%d",&num2);

    push(num1);
    push(num2);

    num1=pop();
    num2=pop();

    printf("value of num1 is %d and value of num2 is %d",num1,num2);

    return 0;
}
