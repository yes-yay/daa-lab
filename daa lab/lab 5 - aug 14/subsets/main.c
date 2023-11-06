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
    printf("null set");

    subsets(set, n);
    return 0;
}

void subsets(int set[], int n)
{
    for (int i = 0; i < pow(2, n); i++)
    {
        int x = binary(i);
        char z[20];
        tostring(z, x, n); // Pass 'n' as the additional argument

        for (int j = 0; j < n; j++)
        {
            if (z[j] == '1')
                printf("%d ", set[j]);
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
