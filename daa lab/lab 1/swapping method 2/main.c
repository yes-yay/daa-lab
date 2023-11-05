//sri rama jayam

#include<stdio.h>

void swap1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;

}





int  main()
{
    int a, b;

    printf("Swap method 1:\n");
    scanf("%d %d",&a,&b);
    swap1(&a, &b);
    printf("a-%d b-%d\n", a, b);

    printf("Swap method 2:\n");
    scanf("%d %d",&a, &b);
    swap2(&a, &b);
    printf("a-%d b-%d\n",a,b);




}
