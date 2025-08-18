// Problem Statement: Shortest Distances Using Breadth-First Search (BFS)

// You have a series of queries regarding undirected graphs. Each graph contains nodes labeled consecutively from 1 to n, and each edge in the graph has a weight of 6 units.

// For each query, you'll receive a list of edges describing an undirected graph. Your task is to compute and report the shortest distance from a given starting node to each of the other nodes using the Breadth-First Search (BFS) algorithm. Return an array of distances from the start node in increasing node number order. If a node is unreachable, return -1 for that node.

// Input:
// q: the number of queries
// n: The number of nodes in the graph.
// m: The number of edges in the graph.
// edges: A list of m lists, each containing two integers u and v representing an edge between nodes u and v.
// s: The starting node number for traversals.
// Output:

// Return a list of distances to nodes in increasing node number order, excluding the start node (-1 if a node is not reachable).
// Constraints:

// 1 <= q <= 10 (number of queries)
// 2 <= n <= 1000
// 1 <= m <= n * (n - 1) / 2
// 1 <= u, v, s <= n
// Sample Input:


// 2
// 4 2
// 1 2
// 1 3
// 1
// 3 1
// 2 3
// 2
// Sample Output:

// 6 6 -1
// -1 6
// Explanation:

// For the first query, the graph consists of 4 nodes and 2 edges. Starting from node 1, the distances to nodes 2 and 3 are both 6 units. Node 4 is unreachable from node 1, hence the distance is -1.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> bfs(int s,vector<pair<int,int>>&edges,int n){
    unordered_map<int, vector<int>>adj;
    for(auto &temp:edges){
        int u=temp.first;
        int v=temp.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // for(auto &val:temp){
        //     cout << val << " ";
        // }
        // cout << endl;
    }
    queue<int>q;
    vector<int>vis(n+1);
    q.push(s);
    vis[s]=1;
    vector<int>dist(n+1,0);
    dist[s]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto& neg:adj[node]){
            if(!vis[neg]){
                dist[neg]+=(dist[node]+6);
                vis[neg]=1;
                q.push(neg);
            }
        }
    }
    vector<int>ans;
    for(int i=0;i<dist.size();i++){
        if(i==0 || i==s) continue;
        if(dist[i]==0) dist[i]=-1;
        ans.push_back(dist[i]);
    }
    return ans;
}
int main(){
	// cout << "Hello World!";
    int q;
    cin >> q;
    while(q--){
        int n,e;
        cin >> n >> e;
        vector<pair<int,int>>edges(e);
        for(int i=0;i<e;i++){
            int u,v;
            cin >> u >> v;
            edges[i].first=u;
            edges[i].second=v;
        }
        int s;
        cin >> s;
        vector<int>temp = bfs(s,edges,n);
        for(int i=0;i<temp.size();i++){
            cout << temp[i] << " ";
        }
        cout << endl;
    }
	return 0;
}
