// Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

// Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

// Examples :

// Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
// Output: [0, 2, 1, -1]
// Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
// Input: V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
// Output: [0, 2, 3, 6, 1, 5]
// Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
// Constraint:
// 1 <= V <= 100
// 1 <= E <= min((N*(N-1))/2,4000)
// 0 <= edgesi,0, edgesi,1 < n
// 0 <= edgei,2 <=105

// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void bfs(int s,vector<int>&cost,unordered_map<int,vector<pair<int,int>>>&adj){
        queue<pair<int,int>>q;
        q.push({s,0});
        while(!q.empty()){
            pair<int,int> node=q.front();
            q.pop();
            for(auto pr:adj[node.first]){
                int curcost=node.second + pr.second;
                if(curcost < cost[pr.first]){
                    cost[pr.first]=curcost;
                    q.push({pr.first,curcost});
                }
            }
        }
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<pair<int,int>>>adj;
		for(auto edge:edges){
			int u,v,w;
			u=edge[0];
			v=edge[1];
			w=edge[2];
			adj[u].push_back({v,w});
		}
        vector<int>cost(V,1e9);
        cost[0]=0;
        bfs(0,cost,adj);
        return cost;
    }
};
