// 200. Number of Islands
// Medium
// Topics
// premium lock icon
// Companies
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// // grid[i][j] is '0' or '1'.
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         int c=0;
//         vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
//         vector<vector<int>>vis(n,vector<int>(m));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]=='0' || vis[i][j]==1) continue;
//                 // we got the land which means grid[i][j]=1
//                 c++;
//                 queue<pair<int,int>>q;
//                 q.push({i,j});
//                 vis[i][j]=1;
//                 while(!q.empty()){
//                     pair<int,int>temp=q.front();
//                     int x=temp.first;
//                     int y=temp.second;
//                     for(auto val:dir){
//                         int nx=x+val.first;
//                         int ny=y+val.second;
//                         if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
//                         if(grid[nx][ny]=='1' && vis[nx][ny]==0){
//                             vis[nx][ny]=1;
//                             q.push({nx,ny});
//                         }
//                     }
//                 }
//             }
//         }
//         return c;
//     }
// };

// using dfs

class Solution {
public:
    int c=0;
    int n,m;    
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis){
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(grid[i][j]=='0') return;
        if(vis[i][j]==1) return;
        vis[i][j]=1;
        dfs(i+1,j,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i,j-1,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
        vector<vector<int>>vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0' || vis[i][j]==1) continue;
                c++;
                dfs(i,j,grid,vis);
            }
        }
        return c;
    }
};