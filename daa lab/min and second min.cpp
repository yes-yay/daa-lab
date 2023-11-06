//sri rama jayam 
#include <iostream> 
using namespace std; 
int main() 
{ 
	int arr[] = {12, 13, 1, 10, 34, 1}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int m = INT_MAX; 
	for (int i = 0; i < n; i++) 
	{ 
		if (arr[i] < m) 
		{ 
			m = arr[i]; 
		} 
	} 
	cout << "min element is: " << m << endl; 

	int smin = INT_MAX; 

	for (int i = 0; i < n; i++) 
	{ 
		if (arr[i] < smin && arr[i] > m) 
		{ 
			smin = arr[i]; 
		} 
	} 
	cout << "second min element is: " << smin << endl; 
	return 0; 
}