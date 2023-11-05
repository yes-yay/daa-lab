//sri rama jayam 
#include<stdio.h>

void main()
{
    int v;
    scanf("%d",&v);
    
    int a[v][v];
    
for(int i=0;i<v;i++)
for(int j=0;j<v;j++){
    scanf("%d",&a[i][j]);
}
int flag1=0;
     for(int i=0;i<v;i++)
for(int j=0;j<v;j++){
   if(a[j][j]==0)
   flag1=1;
}
if(flag1==0)
printf("the matrix is reflexive\n");
else
printf("not a reflexive matrix\n");

int flag2=0;
    for(int i=0;i<v;i++)
for(int j=0;j<v;j++){
   if((a[i][j]==0)&&(a[j][i]==1)){
       flag2=1;
   }
    
}
if(flag2==0)
printf("the matrix is symmetric\n");
else
printf("not a symmetric matrix\n");
int flag3=0;
for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
        for(int k=0;k<v;k++)
{
   if((a[i][j]==1)&&(a[j][k]==1)){
       if(a[i][k]==0){
          flag3=1;
          break;
       }
   }
    
}
if(flag3==0)
    printf("the matrix is transitive");
else
    printf("not a transitive relation");
}