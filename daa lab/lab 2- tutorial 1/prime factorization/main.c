#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//sri rama jayam

int isPrime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int divide_max(int n, int i)
{
    int count = 0;
    while (n % i == 0)
    {
        n = n / i; // Divide n by i, not i * i
        count++;
    }
    return count;
}

int main()
{
    int n;
    printf("enter number: ");
    scanf("%d", &n);

    for (int i = 2; i <= n / 2; i++) // Start i from 2
    {
        if (n % i == 0 && isPrime(i))
        {
            int count = divide_max(n, i);
            printf("%d^%d * ", i, count);
        }
    }

    if(isPrime(n))
        printf("%d^1",n);

    return 0;
}
