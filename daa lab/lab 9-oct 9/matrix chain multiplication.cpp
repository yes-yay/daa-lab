//sri rama jayam 
#include<iostream>
using namespace std;

int row[100];
int column[100];

int storingBestValues[100][100];

int bestChain(int row[], int column[], int i, int j) {

    if(storingBestValues[i][j]!=-1)
        return storingBestValues[i][j];

    if (i == j)
        return 0;
    int min = 1000000;  // Use INT_MAX as a large value
    for (int k = i; k < j; k++) {
        int temp = bestChain(row, column, i, k) + bestChain(row, column, k + 1, j) + row[i] * row[k + 1] * column[j];
        if (temp < min)
            min = temp;
    }

    storingBestValues[i][j]=min;
    return min;
}

int main() {
    // int n;
    // cout << "Enter the number of matrices: ";
    // cin >> n;

    // for (int i = 0; i < n; i++) {
    //     cout << "Enter the number of rows for the " << i + 1 << "th matrix: ";
    //     cin >> row[i];
    //     cout << "Enter the number of columns for the " << i + 1 << "th matrix: ";
    //     cin >> column[i];
    // }

    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            storingBestValues[i][j]=-1;
    
    row[0]=1;
    row[1]=2;
    row[2]=3;
    row[3]=4;
    row[4]=5;
    
    column[0]=2;
    column[1]=3;
    column[2]=4;
    column[3]=5;
    column[4]=6;

    

    cout << bestChain(row, column, 1, 4);  // Start with i = 1 and j = n - 1
    return 0;
}
