//sri rama jayam 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,max,ans,left=-1,right=-1,blks=0,flag=0;
cin>>n;
    
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
  
  max= *max_element(arr, arr + n);
  
  for(int i=max;i>0;i--)
  {
      for(int j=0;j<n;j++)
      {
          if(arr[j]>=i)
          {
              if(flag==0)
             { left=j;
              flag=1;}
              
              else
              {
                  if((flag==1)||(flag==-1))
                  {
                     right=j;
                    
                    if(flag==-1)
                     blks++;
                     
                     flag=-1;
                  }
              }
          }
          
      }
      
      if(((left>-1)&&(right>-1))&&(right-left>1))
      
      ans=ans+(right-left-blks-1);
      
      left=-1;
      right=-1;
      flag=0;
      blks=0;
      
  }
 
 cout<<"ans is :"<<ans;
 
return 0;
}