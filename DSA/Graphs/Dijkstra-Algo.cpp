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

        vector<int>res(V,INT_MAX);

        res[src]=0;
        st.insert({0,src});

        while(!st.empty()){
            auto &it  = *st.begin();
            int node = it.second;
            int d = it.first;
            st.erase(it);

            for(auto& v:adj[node]){
                int neg = v.first;
                int dist = v.second;

                if(d+dist < res[neg]){
                    if(res[neg] != INT_MAX){
                        st.erase({res[neg],neg});
                    }
                    res[neg] = d+dist;
                    st.insert({res[neg],neg});
                }
            }
        }

        return res;
        
    }
};