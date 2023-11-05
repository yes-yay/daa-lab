//sri rama jayam 
#include<stdio.h>
#include<math.h>

int arr[3][2];

int max(int a, int b) { return (a > b)? a : b; }
int knapSack(int i,int W,int w[],int pf[])
{
    if(i==0||W==0)
        return 0;
    
    if(w[i]>W)
            return knapSack(i-1,W,w,pf);
    else
        {
            return max(knapSack(i-1,W-w[i],w,pf)+pf[i],knapSack(i-1,W,w,pf));
        }
}

int main()
{
    int i=3;
    int W=5;
    int w[3]={1,2,3};
    int pf[3]={1,2,3};
    printf("%d",knapSack(i-1,W,w,pf));
}