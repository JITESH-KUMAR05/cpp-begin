// 994. Rotting Oranges
// Medium
// Topics
// premium lock icon
// Companies
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;
        int totalFresh = 0;
        // vector<vector<bool>>vis(m,vector<bool>(n),false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    totalFresh += 1;
                }
            }
        }
        if(totalFresh == 0) return 0; //  there is no need to calculate all are rotten already
        int totalMin = 0;
        while(!q.empty()){
            int sz = q.size();

            for(int u=0;u<sz;u++){
                pair<int,int> node = q.front();
                q.pop();
                int i = node.first;
                int j = node.second;
                for(auto dir : dirs){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1){
                        grid[new_i][new_j] = 2;
                        q.push({new_i,new_j});
                        totalFresh--;
                    }
                }
            }
            totalMin++;
        }

        if(totalFresh == 0) return totalMin-1; // as we are adding one extra at the end where all are rooten already 
        return -1;
    }
};