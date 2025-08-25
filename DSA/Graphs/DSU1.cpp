// 1584. Min Cost to Connect All Points

// arrow-up
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

// Example 1:


// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation: 

// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.
// Example 2:

// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18
 

// Constraints:

// 1 <= points.length <= 1000
// -106 <= xi, yi <= 106
// All pairs (xi, yi) are distinct.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findleader(int node,vector<int>&par){
        if(node==par[node]){
            return node;
        }
        int lnode = findleader(par[node],par);
        return par[node] = lnode;
    }
    void dounion(int u,int v,vector<int>&par,vector<int>&sz){
        int lu = findleader(u,par);
        int lv = findleader(v,par);
        if(sz[lu] > sz[lv]){
            sz[lu] += sz[lv];
            par[lv] = lu;
        }else{
            sz[lv] += sz[lu];
            par[lu] = lv;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        vector<vector<int>>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        vector<int>par(n),sz(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }

        int totoalCst = 0;
        int edgesUsed = 0;
        for(auto &edge:edges){
            int cst = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(findleader(u,par) != findleader(v,par)){
                dounion(u,v,par,sz);
                totoalCst += cst;
                edgesUsed++;

                if(edgesUsed == n-1){
                    break;
                }
            }
        }
        return totoalCst;
    }
};