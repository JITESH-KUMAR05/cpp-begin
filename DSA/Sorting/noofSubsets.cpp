// Given an integer N, which denotes the size of a subset containing N elements. Find the number of ways in which the given set of size N can be divided into subsets.
// Examples:

// Input:  n = 2

// Output: Number of ways = 2

// Explanation: Let the set be {1, 2}

// Subsets will be: {{1},{2}}, {{1, 2}}

// Constraint:

// 1 <= n <= 10
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>res;
vector<int>cur;
void solve(int i,int n){
	if(i==n){
		res.push_back(cur);
		return;
	}
	cur.push_back(i);
	solve(i+1,n);
	cur.pop_back();
	solve(i+1,n);
}


int main(){
	// cout << "Hello World!";
	int n;
	cin >> n;
	solve(1,n);
	cout << res.size();
	return 0;
}
