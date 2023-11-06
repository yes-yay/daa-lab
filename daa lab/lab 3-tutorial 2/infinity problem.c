//sri rama jayam 
#include<stdio.h>

void main()
{
    int size=12000,m=2,low,high;
    
    
    
    int arr[size];

   for(int i=0;i<11599;i++)
     arr[i]=1;
     
     for(int i=11599;i<size;i++)
     arr[i]=0;
    
    while(1)
    {
        if(m<size)
        {
            if(arr[m]==0)
            {
               break;
                
            }
            else
            {
                m=m*2;
            }
            
        }
        else
        {
            break;
        }
     
    }
    
    low=m/2;
    high=m;
    printf("m is%d\n",m);
     printf("low is%d\n",low);
      printf("high is%d\n\n",high);
    
    
    while(1)
    {
        if((high-low)==1)
        {
            if(arr[high]==0)
            printf("0 starts from :%d",high);
            
            else
            printf("0 starts from :%d",low);
            
            break;
        }
        
        else if(high>=size)
        {
             high=size-1;
        }
        
        else
        {
          if(arr[(low+high)/2]==0)
          {
              high=(low+high)/2;
            
          }
          else
          {
            low=(low+high)/2;
          }
        }
        
        printf("low is%d\n",low);
      printf("high is%d\n\n",high);
        
    }
    
}