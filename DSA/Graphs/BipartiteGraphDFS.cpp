// Bipartite Graph

// Given a Graph with V vertices (Numbered from 0 to V-1) and E edges. Check whether the graph is bipartite or not.

// A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:

// All edges connect vertices from one set to vertices in the other set.
// No edges exist between vertices within the same set.
// Examples:

// Input: V = 3, edges[][] = [[0, 1], [1,2]]
// Bipartite-Graph
// Output: true
// Explanation: The given graph can be colored in two colors so, it is a bipartite graph.
// Input: V = 4, edges[][] = [[0, 3], [1, 2], [3, 2], [0, 2]]




// Output: false 
// Explanation: The given graph cannot be colored in two colors such that color of adjacent vertices differs. 
// Constraints:
// 1 ≤ V ≤ 2 * 105
// 1 ≤ edges.size() ≤ 105
// 1 ≤ edges[i][j] ≤ 105

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfs(vector<vector<int>>&adj,int curr,vector<int>&color,int currcolor){
        color[curr] = currcolor;

        for(int &v:adj[curr]){
            if(color[v] == color[curr]) return false;

            if(color[v]==-1){
                int newcolor = 1 - color[curr];
                if(dfs(adj,v,color,newcolor)==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(V,-1);

        // red = 1 , green = 0

        for(int i=0;i<V;i++){
            if(color[i] == -1){
                if(dfs(adj,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;        
    }
};