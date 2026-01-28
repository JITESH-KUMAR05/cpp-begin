// Given an undirected graph with no self loops with V (from 0 to V-1) nodes and E edges, the task is to check if there is any cycle in the undirected graph.

// Note: Solve the problem using disjoint set union (DSU).

// Examples

// Input: 

// Output: 1
// Explanation: There is a cycle between 0->2->4->0
// Input: 

// Output: 0
// Explanation: The graph doesn't contain any cycle
// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function detectCycle() which takes number of vertices in the graph denoting as V and adjacency list adj and returns 1 if graph contains any cycle otherwise returns 0.

// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)

// Constraints:
// 2 ≤ V ≤ 104
// 1 ≤ E ≤ 104

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle using DSU in an undirected graph.
    int find(int u,vector<int>&parent){
        if(u==parent[u]) return u;

        return parent[u]=find(parent[u],parent);
    }
    bool doUnion(int x,int y,vector<int>&parent,vector<int>&rank){
        int x_parent = find(x,parent);
        int y_parent = find(y,parent);

        if(x_parent==y_parent) return true;
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[y_parent]>rank[x_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]+=1;
        }
    }
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>parent(V);
        vector<int>rank(V,0);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        for(int u=0;u<V;u++){
            for(int v:adj[u]){
                if(u<v){
                    int u_parent=find(u,parent);
                    int v_parent = find(v,parent);
                    if(u_parent==v_parent) return true;

                    doUnion(u,v,parent,rank);
                }
            }
        }
        return false;
    }
};