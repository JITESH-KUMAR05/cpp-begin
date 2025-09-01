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
    int findleader(int node,int tp,vector<int>&AP,vector<int>&BP){
        if(tp==1){

        }
        else if(tp==2){

        }
        else if(tp==3){

        }
    }
    void dounion(int u,int v,int lu,int lv,vector<int>&AP,vector<int>&BP,vector<int>&Asz,vector<int>&Bsz,int tp){
        
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
        int c=0;
        vector<vector<int>>commonEdges;
        vector<vector<int>>AliceEdges;
        vector<vector<int>>BobEdges;
        int ini=edges.size();
        for(int i=0;i<ini;i++){
            int tp=edges[i][0];
            int u=edges[i][1];
            int v=edges[i][2];
            if(tp==1){
                AliceEdges.push_back({tp,u,v});
            }else if(tp==2){
                BobEdges.push_back({tp,u,v});
            }else if(tp==3){
                commonEdges.push_back({tp,u,v});
            }
        }
        // first let me prioratise the common edge
        for(int i=0;i<commonEdges.size();i++){
            int tp=commonEdges[i][0];
            int u=commonEdges[i][1];
            int v=commonEdges[i][2];
            int lu=findleader(u,tp,AP,BP);
            int lv=findleader(v,tp,AP,BP);
            if(lu==lv) continue;
            dounion(u,v,lu,lv,AP,BP,Asz,Bsz,tp);
            c++;
        }

        cout << c;
        return c;;
    }
};

// Refer to Remove maximum edges in the same folder for the Class Solution
