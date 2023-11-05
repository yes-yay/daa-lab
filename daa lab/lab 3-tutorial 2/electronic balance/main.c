#include <stdio.h>
#include <math.h>
//sri rama jayam

int main() {
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    float a[n];
    for(int i=0;i<n;i++)
    {
        printf("enter %d value: ",i+1);
        scanf("%f",&a[i]);
    }
    int osum=(n*(n+1))/2;
    float csum=0;
    for(int i=0;i<n;i++){
        csum=csum+(a[i]*(i+1));
    }
    float j=(csum-osum)*10;
    int k=(int) j;
    printf("%d has the odd coin",k);



    return 0;
}
