//sri rama jayam

#include<stdio.h>

int smallest(int a,int b)
{
    if(a<=b)
        return a;

    else
    return b;
}

int nonzero(int a,int b)
{
    if(a==0)
    return b;

    else
    return a;
}

int modulus(int a)
{
    if(a>=0)
    return a;
    else
    return -a;
}

int gcd(int x,int y,int ans)
{
    if(ans==0)
    {
        return modulus(nonzero(x,y));
    }

     else if((y%ans==0)&&(x%ans==0))
    {
        return modulus(ans);
    }
    else
    {
        return gcd(x,y,--ans);
    }

}

int ngcd(int arr[],int size)
{
    int ans=gcd(arr[0],arr[1],smallest(arr[0],arr[1]));

    for(int i=1;i<size-1;i++)
    {
        ans=gcd(ans,arr[i+1],smallest(ans,arr[i+1]));

    }
    return ans;
}

void main()
{
    int n;

    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

   printf("%d",ngcd(arr,n));

}
