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
void bfs(int i,int j,vector<vector<char>>&mat,vector<vector<int>>&vis){
    int n=mat.size();
    int m=mat[0].size();
    queue<pair<int,int>>q;
    q.push({i,j});
    vis[i][j]=1;
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        pair<int,int>temp=q.front();
        q.pop();
        int x=temp.first;
        int y=temp.second;
        for(auto &val:dir){
            int nx=x+val.first;
            int ny=y+val.second;
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(mat[nx][ny]=='.' && vis[nx][ny]==0) {
                vis[nx][ny]=1;
                q.push({nx,ny});
            }

        }
    }
    
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
            bfs(i,j,mat,vis);
        }
    }
    cout << c ;
    return 0;
}