//sri rama jayam 
#include <stdio.h>
#include <math.h>

void tostring(char str[], int num, int n); // Updated function signature

void tostring(char str[], int num, int n)
{
    int i, rem, len = 0, temp;

    temp = num;
    while (temp != 0)
    {
        len++;
        temp /= 10;
    }

    if (len < n)
    {
        int zerosToAdd = n - len;
        for (i = 0; i < zerosToAdd; i++)
        {
            str[i] = '0';
        }
        for (int j = 0; j < len; j++)
        {
            rem = num % 10;
            num = num / 10;
            str[zerosToAdd + len - (j + 1)] = rem + '0';
        }
        str[n] = '\0';
    }
    else
    {
        for (i = 0; i < len; i++)
        {
            rem = num % 10;
            num = num / 10;
            str[len - (i + 1)] = rem + '0';
        }
        str[len] = '\0';
    }
}

struct element{
    int xValue;
    int yValue;
};

int main()
{
    int set[20], n = 2000;
    printf("enter size of set: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("enter value of %d element: ", i + 1);
        scanf("%d", &set[i]);
    }

    //get all the n^2 possible elements 
    //then get the n diagonal elements 
    //do subsets for the remaining n^2 - n elements
    
    struct element allElements[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            allElements[i][j].xValue = set[i];
            allElements[i][j].yValue = set[j];
        }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("(%d,%d) ", allElements[i][j].xValue, allElements[i][j].yValue);
        }
    }

    struct element nonDiagonalElements[100];
    int count=0;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    nonDiagonalElements[count].xValue = allElements[i][j].xValue;
                    nonDiagonalElements[count].yValue = allElements[i][j].yValue;
                    count++;
                }
            }
        }

    for(int i=0;i<pow(n,2)-n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("(%d,%d) ", allElements[j][j].xValue, allElements[j][j].yValue);
        }
        subsets(nonDiagonalElements,pow(n,2)-n);
    }

    
    


    return 0;
}

void subsets(struct element set[100], int n)
{
    for (int i = 0; i < pow(2, n); i++)
    {
        int x = binary(i);
        char z[100];
        tostring(z, x, n); // Pass 'n' as the additional argument

        for (int j = 0; j < n; j++)
        {
            if (z[j] == '1')
                printf("(%d,%d)", set[j].xValue, set[j].yValue);
        }
        printf("\n");
    }
}

int binary(int decimal)
{
    int binary = 0;
    int base = 1;

    while (decimal > 0)
    {
        int remainder = decimal % 2;
        binary += remainder * base;
        base *= 10;
        decimal /= 2;
    }

    return binary;
}
