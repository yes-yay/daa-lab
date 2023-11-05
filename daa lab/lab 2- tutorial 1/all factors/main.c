#include <stdio.h>
#include <stdlib.h>

//sri rama jayam

int main()
{
int n;
printf("enter number: ");
scanf("%d",&n);

for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
            printf("%d ",i);
    }
printf("%d",n);

}
