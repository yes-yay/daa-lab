//sri rama jayam 
#include <bits/stdc++.h> 
using namespace std; 

void findFrequency(int arr[], int n) 
{ 
	unordered_map<int, int> mp; 

	for (int i = 0; i < n; i++) { 
		mp[arr[i]]++; 
	} 

	for (auto i : mp) { 
		cout << "Element " << i.first << " occurs "
			<< i.second << " times" << endl; 
	} 
} 

int main() 
{ 
	int arr[] 
		= { 1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	findFrequency(arr, n); 

	return 0; 
}
