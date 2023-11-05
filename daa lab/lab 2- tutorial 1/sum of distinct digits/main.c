#include <stdio.h>
#include <stdlib.h>
//sri rama jayam

int main()
{
    int integer_count_array[10];
    char n[20];
    int sum = 0, i = 0;

    printf("enter number: ");
    scanf("%s", n);

    for (int i = 0; i < 10; i++)
    {
        integer_count_array[i] = 0;
    }

    while (n[i] != '\0')
    {
        integer_count_array[n[i] - '0'] = 1;
        i++;
    }

    for (int i = 0; i < 10; i++)
    {
        if (integer_count_array[i] > 0)
            sum += i;
    }

    printf("sum of distinct digits in n is: %d ", sum);
    return 0;
}


