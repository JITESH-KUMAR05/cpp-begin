// Time limit: 1.00 s
// Memory limit: 512 MB

// You are given a tree consisting of n nodes.
// The diameter of a tree is the maximum distance between two nodes. Your task is to determine the diameter of the tree.
// Input
// The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,\ldots,n.
// Then there are n-1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.
// Output
// Print one integer: the diameter of the tree.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 5
// 1 2
// 1 3
// 3 4
// 3 5

// Output:
// 3

// Explanation: The diameter corresponds to the path 2 \rightarrow 1 \rightarrow 3 \rightarrow 5.


#include<bits/stdc++.h>
using namespace std;

pair<int,int>bfs(int st,int n,unordered_map<int,vector<int>>&adj){
    queue<pair<int,int>>q;

    vector<int> dist(n+1,-1);

    q.push({st,0});
    dist[st]=0;

    int furthNode=st;
    int e1 = 0;

    while(!q.empty()){
        int u = q.front().first;
        int d = q.front().second;
        q.pop();
        if(d>e1){
            e1=d;
            furthNode=u;
        }
        for(int v:adj[u]){
            if(dist[v]==-1){
                dist[v] = d + 1;
                q.push({v,d+1});
            }
        }
    }
    return {furthNode,e1};
}

int main(){
    int n;
    cin >> n;
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<int,int> p1 = bfs(1,n,adj);
    int d1 = p1.first;

    pair<int,int>p2 = bfs(d1,n,adj);

    int diameter = p2.second;

    cout << diameter;

    return 0;

}