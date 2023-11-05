#include <stdio.h>
#include <stdlib.h>
//sri rama jayam

//gcd using lcm;
int gcd_2(int a,int b)
{   if(lcm(a,b)!=0)
    {
        int gcd=(a*b)/lcm(a,b);
        return gcd;
    }
    else if(a!=0 && b==0)
        return a;
    else if(a==0 && b!=0)
        return b;
    else if(a==0 && b==0)
        return 0;

}
int lcm(int a,int b)
{
if(a!=0 && b==0)
    return 0;
else if(a==0 && b!=0)
    return 0;
else if(a==0 && b==0)
    return 0;
else{
    int max;
    if(a>=b)
        max=a;
    else
        max=b;

    int min;
    if(a<=b)
        min=a;
    else
        max=b;

    for(int i=1;i<min+1;i++)
    {
        if(max*i%min==0)
            return max*i;
    }
}
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


if(n<1)
    {
        printf("No GCD possible.");
    }
if(n==1)
    {
    printf("gcd is %d",array[0]);
    }
if(n==2)
    {
    printf("gcd is %d",gcd_2(array[0],array[1]));
    }

else
    {
        int gcd1=gcd_2(array[0],array[1]);
        for(int i=2;i<n;i++)
        {
            gcd1=gcd_2(gcd1,array[i]);
            //printf("\ngcd is %d ",gcd1));

        }
        printf("\nThe gcd of the given numbers is %d",gcd1);
    }
}
