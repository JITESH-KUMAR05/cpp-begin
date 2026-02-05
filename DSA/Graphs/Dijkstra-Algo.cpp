#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        set<pair<int,int>>st;

        
        
    }
};