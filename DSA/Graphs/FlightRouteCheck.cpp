// CSES Problem Set
// CSES - Flight Routes Check
// There are n cities and m flight connections. Your task is to check if you can travel from any city to any other city using the available flights.
// Input
// The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,\dots,n.
// After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. All flights are one-way flights.
// Output
// Print "YES" if all routes are possible, and "NO" otherwise. In the latter case also print two cities a and b such that you cannot travel from city a to city b. If there are several possible solutions, you can print any of them.
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 4 5
// 1 2
// 2 3
// 3 1
// 1 4
// 3 4

// Output:
// NO
// 4 2

#include<bits/stdc++.h>
using namespace std;

void dfs(int src,unordered_map<int,vector<int>>&adj,vector<bool>&vis){
    vis[src]=true;
    for(int v:adj[src]){
        if(!vis[v]){
            dfs(v,adj,vis);
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    unordered_map<int,vector<int>>adj;
    unordered_map<int,vector<int>>revadj;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        revadj[v].push_back(u);
    }
    vector<bool>vis(n+1,false);
    dfs(1,adj,vis);
    for(int val=1;val<=n;val++){
        if(vis[val]==false){
            cout << "NO" <<endl;
            cout << 1 << " " << val << endl;
            return 0;
        }
    }
    fill(vis.begin(),vis.end(),false);
    dfs(1,revadj,vis);
    for(int val=1;val<=n;val++){
        if(vis[val]==false){
            cout << "NO" << endl;
            cout << val << " " << 1 << endl;
            return 0;
        }
    }
    cout << "YES";
    return 0;
}