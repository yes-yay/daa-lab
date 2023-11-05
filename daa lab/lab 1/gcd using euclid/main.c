#include <stdio.h>
#include <stdlib.h>
//sri rama jayam

//gcd using eucledian algorithm;
int gcd_1(int a,int b){
if(a==0)
    return b;
return gcd_1(b%a,a);
}

int main()
{
int n;
printf("enter number of values 'N': ");
scanf("%d",&n);

int array[100];
for(int i=0;i<n;i++)
    {
        printf("enter array[%d]: ",i);
        scanf("%d",&array[i]);
    }

if(n<=1)
    {
        printf("No GCD possible.");
    }
else
    {
        int gcd1=gcd_1(array[0],array[1]);
        for(int i=2;i<n;i++)
        {
            gcd1=gcd_1(gcd1,array[i]);
        }
        printf("The gcd of the given numbers is %d",gcd1);
    }



}



