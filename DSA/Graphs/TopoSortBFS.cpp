#include <bits/stdc++.h> 
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int>inDeg(v,0);
    unordered_map<int,vector<int>>adj;
    for(auto edge:edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        inDeg[v]++;
    }
    queue<int>q;
    for(int i=0;i<v;i++){
        if(inDeg[i]==0){
            q.push(i);
        }
    }
    vector<int>res;
    while(q.empty()){
        
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int v:adj[node]){
                inDeg[v]--;
                if(inDeg[v]==0){
                q.push(v);
            }
            }
        
    }
    return res;
}