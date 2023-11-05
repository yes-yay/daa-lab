#include <stdio.h>
#include <stdlib.h>
//sri rama jayam
int main()
{
    double array[10];

    for (int i = 0; i < 10; i++)
    {
        printf("enter value for box no %d: ", i + 1);
        scanf("%lf", &array[i]);
    }

    int S1 = array[0] + array[1] + array[2];
    int S2 = array[3] + array[4] + array[5];
    int S3 = array[6] + array[7] + array[8] + array[9];

    if (S1 == S2)
    {
        int S4 = array[6] + array[7];
        int S5 = array[8] + array[9];

        if (S4 > S5 && array[6] > array[7])
            printf("7th box has the odd coin\n");
        else if (S4 > S5 && array[6] < array[7])
            printf("8th box has the odd coin\n");
        else if (S5 > S4 && array[8] > array[9])
            printf("9th box has the odd coin\n");
        else if (S5 > S4 && array[8] < array[9])
            printf("10th box has the odd coin\n");
    }
    else if (S1 > S2)
    {
        if (array[0] == array[1])
            printf("box 3 has the odd coin\n");
        else if (array[0] > array[1])
            printf("box 1 has the odd coin\n");
        else if (array[0] < array[1])
            printf("box 2 has the odd coin\n");
    }
    else if (S2 > S1)
    {
        if (array[3] == array[4])
            printf("box 6 has the odd coin\n");
        else if (array[3] > array[4])
            printf("box 4 has the odd coin\n");
        else if (array[3] < array[4])
            printf("box 5 has the odd coin\n");
    }

    return 0;
}
