#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void DFS(unordered_map<int, vector<int>>&adj,int u,vector<bool>&visited,vector<int>&result){
        if(visited[u]==true) return;
        visited[u] = true;
        result.push_back(u);
        for(int &v : adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited,result);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& mp) {
        unordered_map<int, vector<int>>adj;
        
        for(int u=0;u<mp.size();u++){
            for(auto v = mp[u].begin();v!=mp[u].end();v++){
                adj[u].push_back(*v);
            }
        }
        
        vector<int> result;
        vector<bool>visited(mp.size(),false);
        
        DFS(adj,0,visited,result);
        return result;
        
    }
};