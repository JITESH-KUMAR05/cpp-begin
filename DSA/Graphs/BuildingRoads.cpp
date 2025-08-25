// Problem Title: City Connectivity Expansion

// Problem Description
// Byteland consists of n cities, and currently, there are m roads connecting some of them. The objective is to enhance the city connectivity by constructing new roads, ensuring there is a route between any two cities.

// Your task is to find the minimum number of additional roads required for this enhanced connectivity and determine the configuration of these new roads.

// Input
// The first line contains two integers n and m (1 ≤ n ≤ 10^5, 1 ≤ m ≤ 2 × 10^5): the number of cities and existing roads. The cities are numbered 1, 2, ..., n.
// Following that, there are m lines describing the existing roads. Each line has two integers a and b, representing a road between those cities. A road always connects two different cities, and there is at most one road between any two cities.
// Output
// Print an integer k: the number of required additional roads.
// Then, print k lines, each describing a new road. You can print any valid solution.

// Constraints
// 1 ≤ a, b ≤ n
// Example
// Input

// 4 2
// 1 2
// 3 4
// Output

// 1
// 2 3
// Note
// In this example, one additional road (2 to 3) is required to connect all cities.

#include<bits/stdc++.h>
using namespace std;
void bfs(int s,unordered_map<int,vector<int>>&adj,vector<bool>&vis){
    queue<int>q;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int v:adj[node]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m ;
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(n+1,false);
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans.push_back(i);
            bfs(i,adj,vis);
        }
    }
    int c = ans.size();
    cout << c-1 << endl;
    for(int i=1;i<ans.size();i++){
        cout << ans[i-1] << " " << ans[i] << endl;
    }
}