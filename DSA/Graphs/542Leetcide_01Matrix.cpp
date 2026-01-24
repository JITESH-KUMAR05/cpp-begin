// 542. 01 Matrix
// Medium
// Topics
// premium lock icon
// Companies
// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two cells sharing a common edge is 1.

 

// Example 1:


// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
// Example 2:


// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// mat[i][j] is either 0 or 1.
// There is at least one 0 in mat.
 

// Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>res(m,vector<int>(n));
        int c = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    res[i][j]=0;
                    q.push({i,j});
                }
                else{
                    mat[i][j]=-1;
                }
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto dir:dirs){
                int new_i = node.first + dir[0];
                int new_j = node.second + dir[1];
                if(new_i>=0 && new_i<m && new_j>=0 && new_j<n){
                    if(mat[new_i][new_j]==-1){
                        q.push({new_i,new_j});
                        res[new_i][new_j]= res[node.first][node.second] + 1;
                        mat[new_i][new_j] = 1;
                    }
                }
            }

        }
        return res;
    }
};