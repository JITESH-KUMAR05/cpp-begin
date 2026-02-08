// Q4. Maximum Score Using Exactly K Pairs
// Hard
// 6 pt.
// You are given two integer arrays nums1 and nums2 of lengths n and m respectively, and an integer k.

// You must choose exactly k pairs of indices (i1, j1), (i2, j2), ..., (ik, jk) such that:

// 0 <= i1 < i2 < ... < ik < n
// 0 <= j1 < j2 < ... < jk < m
// For each chosen pair (i, j), you gain a score of nums1[i] * nums2[j].

// The total score is the sum of the products of all selected pairs.

// Return an integer representing the maximum achievable total score.

//  

// Example 1:

// Input: nums1 = [1,3,2], nums2 = [4,5,1], k = 2

// Output: 22

// Explanation:

// One optimal choice of index pairs is:

// (i1, j1) = (1, 0) which scores 3 * 4 = 12
// (i2, j2) = (2, 1) which scores 2 * 5 = 10
// This gives a total score of 12 + 10 = 22.

// Example 2:

// Input: nums1 = [-2,0,5], nums2 = [-3,4,-1,2], k = 2

// Output: 26

// Explanation:

// One optimal choice of index pairs is:

// (i1, j1) = (0, 0) which scores -2 * -3 = 6
// (i2, j2) = (2, 1) which scores 5 * 4 = 20
// The total score is 6 + 20 = 26.

// Example 3:

// Input: nums1 = [-3,-2], nums2 = [1,2], k = 2

// Output: -7

// Explanation:

// The optimal choice of index pairs is:

// (i1, j1) = (0, 0) which scores -3 * 1 = -3
// (i2, j2) = (1, 1) which scores -2 * 2 = -4
// The total score is -3 + (-4) = -7.

//  

// Constraints:

// 1 <= n == nums1.length <= 100
// 1 <= m == nums2.length <= 100
// -106 <= nums1[i], nums2[i] <= 106
// 1 <= k <= min(n, m)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    ll dp[105][105][105];
    ll NEG = -1e15;
    ll UNSET = -1e16;

    ll helper(int i,int j,int k,vector<int>& nums1, vector<int>& nums2){
        if(k==0) return 0;
        // this means all pairs collected

        // if the index is out of bound means that pairs are impossible so
        if(i >= nums1.size() || j >= nums2.size()) return NEG;
        if(nums1.size() - i < k || nums2.size() - j < k) return NEG;

        if(dp[i][j][k] != UNSET) return dp[i][j][k];
        // op1
        ll res = helper(i+1,j,k,nums1,nums2);
        // op2
        res = max(res,helper(i,j+1,k,nums1,nums2));

        // op3 taking both
        ll take = (ll)nums1[i] * nums2[j] + helper(i+1,j+1,k-1,nums1,nums2);

        res = max(res,take);

        return dp[i][j][k] = res;
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                for(int l=0;l<105;l++){
                    dp[i][j][l] = UNSET;
                }
            }
        }
        return helper(0,0,k,nums1,nums2);
    }
};