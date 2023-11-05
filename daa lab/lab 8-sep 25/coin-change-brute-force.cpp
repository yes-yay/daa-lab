#include <iostream>

using namespace std;

int q,ans,d,flag=0;

void change(int sum,int coin[],int count)
{
    if(sum>0)
    {
        for(int i=0;i<d;i++)
         change(sum-coin[i],coin,count+1);
    }
   
    else if(sum==0)
    {
        if(flag==0)
       { 
           ans=count;
       flag=1;
       }
        else if(count<ans)
        {
            ans=count;
        }

    }

}


int main()
{

 cout<<"enter no of denominations\n";
 
cin>>d;
 
 int coin[d];
 
cout<<"enter the denominations\n";
 
for(int i=0;i<d;i++)
 {
     cin>>coin[i];
 }
 
  int sum=0;
  
  cout<<"enter the required change\n";
  
  cin>>q;
  
 change(q,coin,0);
 
 cout<<ans;
 
return 0;
}