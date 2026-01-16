// Connected Components in an Undirected Graph
// Difficulty: MediumAccuracy: 48.5%Submissions: 33K+Points: 4
// Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

// Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

// Note: You can return the components in any order, driver code will print the components in sorted order.

// Examples :

// Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
// Output: [[0, 1, 2], [3, 4]]
// Explanation:

// Input: V = 7, edges[][] = [[0, 1], [6, 0], [2, 4], [2, 3], [3, 4]]
// Output: [[0, 1, 6], [2, 3, 4], [5]]
// Explanation:

// Constraints:
// 1 ≤ V, E ≤ 105
// 0 ≤ edges[i][0], edges[i][1] < V

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>& vis,vector<int>&temp){
        vis[u]=true;
        temp.push_back(u);
        for(auto v:adj[u]){
            if(!vis[v]){
                dfs(v,adj,vis,temp);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(V,false);
        vector<vector<int>>res;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vector<int>temp;
                dfs(i,adj,vis,temp);
                res.push_back(temp);
            }
        }
        return res;
    }
};
