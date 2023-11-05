#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//sri rama jayam
int isPrime(int n)
{
    if(n==1)
    {
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }
return 1;
}

int main()
{
    int n;
    printf("enter number: ");
    scanf("%d",&n);

    for(int i=2;i<n/2+1;i++)
    {
        if(n%i==0 && isPrime(i))
        {
            printf("%d ",i);
        }

    }

    if(isPrime(n))
        printf("%d",n);
    return 0;
}
