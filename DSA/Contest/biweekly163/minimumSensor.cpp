
// Code
// Testcase
// Testcase
// Test Result
// Q1. Minimum Sensors to Cover Grid
// Solved
// Medium
// 4 pt.
// You are given n × m grid and an integer k.

// A sensor placed on cell (r, c) covers all cells whose Chebyshev distance from (r, c) is at most k.

// The Chebyshev distance between two cells (r1, c1) and (r2, c2) is max(|r1 − r2|,|c1 − c2|).

// Your task is to return the minimum number of sensors required to cover every cell of the grid.

//  

// Example 1:

// Input: n = 5, m = 5, k = 1

// Output: 4

// Explanation:

// Placing sensors at positions (0, 3), (1, 0), (3, 3), and (4, 1) ensures every cell in the grid is covered. Thus, the answer is 4.

// Example 2:

// Input: n = 2, m = 2, k = 2

// Output: 1

// Explanation:

// With k = 2, a single sensor can cover the entire 2 * 2 grid regardless of its position. Thus, the answer is 1.

//  

// Constraints:

// 1 <= n <= 103
// 1 <= m <= 103
// 0 <= k <= 103
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSensors(int n, int m, int k) {
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    for(int r=i;r<=2*k+i;r++){
                        for(int c=j;c<=2*k+j;c++){
                            if(r>=n || c>=m) break;
                            visited[r][c]=true;
                        }
                    }
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
