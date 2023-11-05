#include <stdio.h>
#include <stdlib.h>

//sri rama jayam

int main()
{
int n;
printf("enter number: ");
scanf("%d",&n);

int sum=0;

for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
            sum=sum+i;
    }
printf("%d",sum+n);
}
