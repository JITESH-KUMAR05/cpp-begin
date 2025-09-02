// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
// Hard
// Alice and Bob have an undirected graph of n nodes and three types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can be traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

 

// Example 1:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// Output: 2
// Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
// Example 2:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// Output: 0
// Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
// Example 3:



// Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// Output: -1
// Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 

 

// Constraints:

// 1 <= n <= 105
// 1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
// edges[i].length == 3
// 1 <= typei <= 3
// 1 <= ui < vi <= n
// All tuples (typei, ui, vi) are distinct.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findleader(int node,vector<int>&parent){
        if(parent[node]==node) return node;
        return parent[node]=findleader(parent[node],parent);
    }
    bool dounion(int u,int v,vector<int>&parent,vector<int>&sz){
        int lu=findleader(u,parent);
        int lv=findleader(v,parent);
        
        if(lu==lv) return false;
        if(sz[lu]>sz[lv]){
            sz[lv]+=sz[lv];
            parent[lv]=lu;
        }else{
            sz[lu]+=sz[lv];
            parent[lu]=lv;
        }
        return true;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>AP(n+1);
        vector<int>Asz(n+1);
        vector<int>BP(n+1);
        vector<int>Bsz(n+1);
        for(int i=1;i<=n;i++){
            AP[i]=BP[i]=i;
            Asz[i]=Bsz[i]=1;
        }
        int edges_used=0;
        int noc_alice=n;
        int noc_bob=n;
        
        for(auto &edge:edges){
            if(edge[0]==3){
                bool bob_used=dounion(edge[1],edge[2],BP,Bsz);
                bool alice_used=dounion(edge[1],edge[2],AP,Asz);

                if(alice_used || bob_used) {
                    edges_used++;
                    noc_alice--;
                    noc_bob--;
                }
            }
        }

        for(auto &edge:edges){
            if(edge[0]==2){
                bool bob_used=dounion(edge[1],edge[2],BP,Bsz);
                // bool alice_used=dounion(edge[1],edge[2],AP,Asz);

                if(bob_used) {
                    edges_used++;
                    noc_bob--;
                }
            }
        }
        for(auto &edge:edges){
            if(edge[0]==3){
                // bool bob_used=dounion(edge[1],edge[2],BP,Bsz);
                bool alice_used=dounion(edge[1],edge[2],AP,Asz);

                if(alice_used) {
                    edges_used++;
                    noc_alice--;
                }
            }
        }

        if(noc_alice==1 && noc_bob==1){
            return edges.size()-edges_used;
        }
        return -1;
    }
};

// Refer to Remove maximum edges in the same folder for the Class Solution
