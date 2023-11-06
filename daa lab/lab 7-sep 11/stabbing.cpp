//sri rama jayam 
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout<<"enter n: "<<endl;
    cin>>n;
    
	int person = n;

	vector<int> a(person);

	for (int i = 0; i < person; i++) {
		a[i] = i + 1;
	}
	int pos = 0;
	while (a.size() > 1) {
		pos++;
		pos %= a.size();
		a.erase(a.begin() + pos);
	}

	cout << a[0];

	return 0;
}
