//sri rama jayam 
#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    cout << "Enter n: " << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a[" << i << "]: " << endl;
        cin >> arr[i];
    }

    int count0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            swap(&arr[i], &arr[count0]);
            count0++;
        }
    }

    int count1 = count0 + 1;
    for (int i = count0 + 1; i < n; i++)
    {
        if (arr[i] == 1)
        {
            swap(&arr[i], &arr[count1]);
            count1++;
        }
    }

    cout << "Array is now printed" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
