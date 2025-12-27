// we need to detect the cycle in an undirected graph 

#include<bits/stdc++.h>
using namespace std;

bool dfs(int u,int p,unordered_map<int,vector<int>>&adj,vector<bool>&vis){
    vis[u]=true;
    for(int &v:adj[u]){
        if(v==p) continue;
        if(vis[v]==true) return true;
        if(dfs(v,u,adj,vis)) return true;
    }
    return false;
}

bool bfs(int u,vector<vector<int>>& adj,vector<bool>&visited){
        queue<pair<int,int>>q;
        q.push({u,-1});
        visited[u]=true;
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int source=p.first;
            int parent=p.second;
            for(auto &v:adj[source]){
                if(!visited[v]){
                    q.push({v,source});
                    visited[v]=true;
                }else if(v!=parent){
                    return true;
                }
            }
        }
        return false;
    }
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }       
        vector<bool>vis(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i] && dfs(i,-1,adj,vis)){
                return true;
            }
        }
        return false;
    }
};