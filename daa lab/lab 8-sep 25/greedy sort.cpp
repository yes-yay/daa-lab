//sri rama jayam
#include <iostream>
using namespace std;

void selsort(int arr[], int n)
{
	int i, j, mini;

	for (i = 0; i < n - 1; i++) {

		mini = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[mini])
				mini = j;
		}

		if (mini != i)
			swap(arr[mini], arr[i]);
	}
}

void printarr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
    {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };

	selsort(arr, 5);
	cout << "Sorted array: \n";
	printarr(arr, n);
	return 0;
}