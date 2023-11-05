#include <stdio.h>
#include <stdlib.h>

//sri rama jayam

int main()
{
    int num1,num2;

    printf("enter number 1" );
    scanf("%d",&num1);

    printf("enter number 2: ");
    scanf("%d",&num2);

    int temp=num1;
    num1=num2;
    num2=temp;

    printf("num1 is now %d and num2 is now %d",num1,num2);
}
