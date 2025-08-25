// Title: "Hierarchy Exploration"

// Problem Statement:

// In an organization, employees form a hierarchical tree structure, with each employee having a boss, except for the general director. You are tasked with handling queries regarding an employee's boss k levels higher in the hierarchy.

// Input:
// The first line contains two integers n and q, denoting the number of employees and queries, respectively. The employees are numbered from 1 to n, and employee 1 is the general director.
// The second line consists of n-1 integers e_2, e_3, ... e_n, where for each employee 2, 3, ..., n, the number denotes their boss.
// The following q lines describe the queries. Each line contains two integers x and k: inquiring about the boss of employee x k levels higher up the hierarchy.

// Output:
// Print the response for each query. If there isn't a boss at the specified level, print -1.

// Constraints:
// 1 ≤ n, q ≤ 2 × 10^5
// 1 ≤ e_i ≤ i - 1
// 1 ≤ x ≤ n
// 1 ≤ k ≤ n
// Example:
// Input:


// 5 3
// 1 1 3 3
// 4 1
// 4 2
// 4 3
// Output:

// 3
// 1
// -1
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	// cout << "Hello World!";
    int n,q;
    cin >> n >> q;
    vector<int>boses(n);
    unordered_map<int,int>adj;
    adj[1] = -1;
    for(int i=2;i<=n;i++){
        int u,v;
        u = i;
        cin >> v;
        adj[u]=v;
    }
    while(q--){
        int node,k;
        cin >> node >> k;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            q.push(adj[u]);
            k--;
            if(k==0) {
                cout << adj[u] << endl;
                break;
            }
			if(u==adj[u] && k!=0) {
				cout << -1;
				break;
			}
        }
        // if(k!=0) cout << -1;
    }
	return 0;
}
