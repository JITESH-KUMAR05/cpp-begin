//  this is for topological sort 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int u,vector<bool> &vis,stack<int> &st,unordered_map<int,vector<int>> &adj){
        vis[u]=true;

        for(int v:adj[u]){
            if(!vis[v]){
                dfs(v,vis,st,adj);
            }
        }
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges){
            int u = edge[0];To
            int v = edge[1];
            adj[u].push_back(v);

        }

        vector<int>res;
        stack<int>st;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};