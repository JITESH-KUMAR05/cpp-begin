// Given a tree of n nodes, your task is to find a centroid, i.e., a node such that when it is appointed the root of the tree, each subtree has at most \lfloor n/2 \rfloor nodes.
// Input
// The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,…,n.
// Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
// Output
// Print one integer: a centroid node. If there are several possibilities, you can choose any of them.
// Constraints

// 1 <=n <= 2 * 10^5
// 1 <= a,b <= n

// Example
// Input:
// 5
// 1 2
// 2 3
// 3 4
// 3 5

// Output:
// 3

#include<bits/stdc++.h>
using namespace std;

void findSize(int u,int p,vector<vector<int>>&adj,vector<int>&subtreeSize){
    subtreeSize[u]=1;
    for(int v:adj[u]){
        if(v==p) continue;
        findSize(v,u,adj,subtreeSize);
        subtreeSize[u] += subtreeSize[v];
    }
}

int findCentroid(int u,int p,vector<vector<int>>&adj,vector<int>&subtreeSize,int n){
    for(int v:adj[u]){
        if(v==p)continue;
        if(subtreeSize[v]> n/2){
            return findCentroid(v,u,adj,subtreeSize,n);
        }
    }

    return u;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>>adj(n+1);
    vector<int>subtreeSize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findSize(1,0,adj,subtreeSize);

    int centroid = findCentroid(1,0,adj,subtreeSize,n);

    cout << centroid;
    
    return 0;

}