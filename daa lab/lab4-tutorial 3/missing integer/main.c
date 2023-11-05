#include <stdio.h>
#include <stdlib.h>

//sri rama jayam

int getMissingNo(int a[], int n)
{
    int i;

    int x1 = a[0];

    int x2 = 0;

    for (i = 1; i < n; i++)
        x1 = x1 ^ a[i];

    for (i = 1; i <= n ; i++)
        x2 = x2 ^ i;

    return (x1 ^ x2);
}

void main()
{
    int arr[] = {0,1 , 2, 3, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);

    int miss = getMissingNo(arr, N);
    printf("%d", miss);
}
