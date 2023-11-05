#include <stdio.h>
#include <math.h>

//sri rama jayam 


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

int set[20];

int main()
{   

    int numberOfElements;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &numberOfElements);

    for (int i = 0; i < numberOfElements; i++)
    {
        printf("Enter the value of %d element: ", i + 1);
        scanf("%d", &set[i]);
    }

    struct element allElements[numberOfElements][numberOfElements];

    for(int i=0;i<numberOfElements;i++)
    {
        for(int j=0;i<numberOfElements;j++)
        {
            allElements[i][j].xValue = set[i];
            allElements[i][j].yValue = set[j];
        }
    }

    struct element diagonalElements[numberOfElements];
    for(int i=0;i<numberOfElements;i++)
    {
        diagonalElements[i].xValue = set[i];
        diagonalElements[i].yValue = set[i];
    }   

    struct element nonDiagonalElements[pow(numberOfElements,2)-numberOfElements];
    int k=0;
    for(int i=0;i<numberOfElements;i++)
    {
        for(int j=0;j<numberOfElements;j++)
        {
            if(i!=j)
            {
                nonDiagonalElements[k].xValue = set[i];
                nonDiagonalElements[k].yValue = set[j];
                k++;
            }
        }
    }

    printf("The reflexive subsets are: \n");
    subsets(nonDiagonalElements, pow(numberOfElements,2)-numberOfElements);

    return 0;
}

void subsets(struct element set[], int n)
{
    for (int i = 0; i < pow(2, n); i++)
    {
        int x = binary(i);
        char z[20];
        tostring(z, x, n); // Pass 'n' as the additional argument

        for (int j = 0; j < n; j++)
        {
            if (z[j] == '1')
                printf("(%d %d)", set[j].xValue, set[j].yValue);
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

