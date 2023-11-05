#include <stdio.h>
#include <stdlib.h>
//sri rama jayam



int main()
{

    int array[100];
    int n;
    printf("enter size: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("enter array[%d]: ",i);
        scanf("%d",&array[i]);
    }

    int distinct_array[3];

    distinct_array[0]=array[0];

    int flag=0;
    for(int i=1;i<n;i++)
    {
        if(array[i]!=distinct_array[0])
        {
            distinct_array[1]=array[i];
            flag=1;
            break;
        }

    }

    if(flag==0)
    {
        printf("\nnot distinct enough");
    }
    else
    {
    int flag2=0;

    for(int i=0;i<n;i++)
    {
        if(array[i]!=distinct_array[0]&& array[i]!=distinct_array[1])
        {
          distinct_array[2]=array[i];
          flag2=1;
          break;
        }
    }

        if(flag2==0)
        {
            printf("\nnot distinct enough");
        }
        else
        {
            if((distinct_array[0]>distinct_array[1]&&distinct_array[0]<distinct_array[2])||(distinct_array[0]>distinct_array[2]&&distinct_array[0]<distinct_array[1]))
                printf("%d",distinct_array[0]);
            if((distinct_array[1]>distinct_array[0]&&distinct_array[1]<distinct_array[2])||(distinct_array[1]>distinct_array[2]&&distinct_array[1]<distinct_array[0]))
                printf("%d",distinct_array[1]);
            if((distinct_array[2]>distinct_array[1]&&distinct_array[2]<distinct_array[0])||(distinct_array[2]>distinct_array[0]&&distinct_array[2]<distinct_array[1]))
                printf("%d",distinct_array[2]);
        }
    }

    /*for(int i=0;i<3;i++)
    {
        printf("\n%d",distinct_array[i]);
    }*/





}
