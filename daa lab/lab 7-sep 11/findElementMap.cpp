//sri rama jayam 
#include<iostream>
using namespace std;

int find_num(int arr[5][5], int x, int n){
    int st = 0,end=n-1, mid, row=-1;
    while(st<=end)//finding row
    {
        mid=(st+end)/2;
        if((arr[mid][0]<=x) && (x<=arr[mid][n-1]))
        {
            row=mid;
            break;
        }
        else if(x < arr[mid][0])
        {
            end=mid-1;
        }
        else{
            st = mid+1;
        }
    }
    
    if(row==-1)
    return 0;//not found
    
    st=0, end=n-1;
    while(st<=end){
        mid = (st+end)/2;
        if(arr[row][mid]==x)
        return 1;//ele found
        else if(x<arr[row][mid])
        end=mid-1;
        else
        st=mid+1;
    }
    return 0;//notfound
}

int main()
{
    
    int arr[][5]= {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25},
    };
    
    int x;
    cout << "Enter ele:";
    cin >> x;
    
   int ans= find_num(arr,x, 5);
    if(ans==1)
    cout << "present" << endl;
    else
    cout << "not present" << endl;
    
    return 0;
}