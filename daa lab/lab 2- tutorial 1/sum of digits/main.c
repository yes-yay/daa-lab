#include <stdio.h>
#include <stdlib.h>
//sri rama jayam

int main()
{
    char n[20];
    printf("enter n: ");
    scanf("%s", n);

    int i = 0, sum = 0;
    while (n[i] != '\0')
    {
        sum = sum + (n[i]-'0');
        i++;
    }

    printf("sum of digits of n is: %d", sum);
    return 0;
}
