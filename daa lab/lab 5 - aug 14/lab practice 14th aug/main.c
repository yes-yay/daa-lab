#include<stdio.h>

int fibArray[100];

int fib(int n)
{
    if(fibArray[n]!=-1)
        return fibArray[n];
    if(n==0)
    {
        fibArray[0]=0;
        return 0;
    }
    else if(n==1)
    {
        fibArray[1]=1;
        return 1;
    }
    else
    {
        fibArray[n]=fib(n-1)+fib(n-2);
        return fib(n-1) + fib(n-2);
    }
}
void main()
{
    for(int i=0;i<100;i++)
    {
        fibArray[i]=-1;
    }
    int f = fib(6);
    printf("%d\n\n",f);

    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int a[n];
    a[0] = 1;
    a[1] = 1;
    for(int i=2;i<n;i++)
        a[i] = a[i-1] + a[i-2];

    printf("%d",a[n-1]);
}
