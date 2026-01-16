// Detect Cycle in directed graph GFG


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool> &vis,vector<bool>&inRec){
        vis[u]=true;
        inRec[u]=true;

        for(int v:adj[u]){
            if(vis[v]==true && inRec[v]==true) return true;
            // if(vis[v]==true) continue;
            if(!vis[v]) {
                if(dfs(v,adj,vis,inRec)) return true;
            }
        }
        inRec[u]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<bool>vis(V,false);
        vector<bool>inRec(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,inRec)){
                    return true;
                }
            }
        }

        return false;
        
    }
};