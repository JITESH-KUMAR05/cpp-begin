// You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
// Input
// The first input line has two integers n and m: the height and width of the map.
// Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
// Output
// Print one integer: the number of rooms.
// Constraints

// 1 \le n,m \le 1000

// Example
// Input:
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

// Output:
// 3

#include<bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<char>>&mat,vector<vector<int>>&vis){
    int n=mat.size();
    int m=mat[0].size();
    if(i<0 || i>=n || j<0 || j>=m) return;
    if(mat[i][j]=='#') return;
    if(vis[i][j]==1) return;
    vis[i][j]=1;
    dfs(i+1,j,mat,vis);
    dfs(i-1,j,mat,vis);
    dfs(i,j+1,mat,vis);
    dfs(i,j-1,mat,vis);
    
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>>mat(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    int c=0;
    vector<vector<int>>vis(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='#' || vis[i][j]==1) continue;
            c++;
            dfs(i,j,mat,vis);
        }
    }
    cout << c ;
    return c;
}