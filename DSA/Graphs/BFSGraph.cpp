// Title-Breadth First Search

// You are tasked with implementing Breadth-First Search (BFS) on a graph represented using an adjacency list. The vertices are numbered from 0 to V-1, and the graph may have multiple test cases.

// Input Format:

// The first line contains an integer T, denoting the number of test cases.
// For each test case, the first line contains two space-separated integers, V and E, where V is the number of vertices, and E is the number of edges.
// The next E lines contain two space-separated integers, u and v, representing an edge from vertex u to vertex v.
// Output Format:

// For each test case, output V lines, where each line contains the cost from the source vertex (always vertex 0) to vertex V.
// If there is no path from the source to a particular vertex, print -1 for that vertex.
// Constraints:

// 1 <= T <= 10
// 1 <= V, E <= 10^3
// 0 <= u, v < V
// Sample Input:

// 1
// 7 14
// 0 5
// 5 0
// 0 1
// 1 0
// 1 2
// 2 1
// 2 5
// 5 2
// 0 3
// 3 0
// 3 4
// 4 3
// 4 5
// 5 4

// Sample Output:

// 0
// 1
// 2
// 1
// 2
// 1
// -1

// Explanation:
// In the given sample, there is a single test case with a graph having 7 vertices and 14 edges. The output represents the cost from the source (vertex 0) to each vertex using Breadth-First Search. If there is no path from the source to a vertex, -1 is printed. The edges are processed in the order they are input.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(int src,unordered_map<int,vector<int>>&adj,vector<int>&ans){
    queue<int>q;
    ans[src]=0;
    q.push(src);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int &v:adj[u]){
            int ccost = ans[u] + 1;
            if(ccost < ans[v]){
                q.push(v);
                ans[v] = ccost;
            }
        }
    }
}
int main(){
	// cout << "Hello World!";
    int t;
    cin >> t;
    while(t--){
        int v,e;
        cin >> v >> e;
        unordered_map<int,vector<int>>adj;
        vector<int>ans(v,1e9);
        for(int i=0;i<e;i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        bfs(0,adj,ans);
        for(int i=0;i<ans.size();i++){
            if(ans[i] == 1e9){
                cout << -1 << endl;
            }else{
                cout << ans[i] << endl;
            }
        }
    }
	return 0;
}
