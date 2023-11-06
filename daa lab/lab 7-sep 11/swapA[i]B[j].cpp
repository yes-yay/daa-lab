//sri rama jayam 
#include<iostream>
using namespace std;

int arraySum(int a[100],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    return sum;
}

int binarySearch(int arr[], int l, int r, float x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        if (arr[m] == x)
            return m;
 
        if (arr[m] < x)
            l = m + 1;
 
        else
            r = m - 1;
    }
     return -1;
}
 


int main()
{
    int a[]={1,2,3,4,5};
    int b[]={8,7,3,1};

    int asum=arraySum(a,5);
    int bsum=arraySum(b,4);

    int correctSum=(asum+bsum)/2;

    for(int i=0;i<5;i++)
    {
        int result=binarySearch(b,0,3,(bsum-asum)/2 + a[i]);
        if(result!=-1)
        {
            cout<<"i: "<<i<<endl;
            cout<<"j: "<<result<<endl;
            break;
        }
        
        
    }
}