// Q1. Maximum Score of a Split
// Medium
// 4 pt.
// You are given an integer array nums of length n.

// Choose an index i such that 0 <= i < n - 1.

// For a chosen split index i:

// Let prefixSum(i) be the sum of nums[0] + nums[1] + ... + nums[i].
// Let suffixMin(i) be the minimum value among nums[i + 1], nums[i + 2], ..., nums[n - 1].
// The score of a split at index i is defined as:

// score(i) = prefixSum(i) - suffixMin(i)

// Return an integer denoting the maximum score over all valid split indices.

//  

// Example 1:

// Input: nums = [10,-1,3,-4,-5]

// Output: 17

// Explanation:

// The optimal split is at i = 2, score(2) = prefixSum(2) - suffixMin(2) = (10 + (-1) + 3) - (-5) = 17.

// Example 2:

// Input: nums = [-7,-5,3]

// Output: -2

// Explanation:

// The optimal split is at i = 0, score(0) = prefixSum(0) - suffixMin(0) = (-7) - (-5) = -2.

// Example 3:

// Input: nums = [1,1]

// Output: 0

// Explanation:

// The only valid split is at i = 0, score(0) = prefixSum(0) - suffixMin(0) = 1 - 1 = 0.

//  

// Constraints:

// 2 <= nums.length <= 105
// -109​​​​​​​ <= nums[i] <= 109

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long>preSum(n);
        vector<int>suffMin(n);
        preSum[0]=nums[0];
        for(int i=1;i<n;i++){
            preSum[i] = preSum[i-1] + nums[i];
        }
        suffMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffMin[i] = min(suffMin[i+1],nums[i]);
        }

        long long ans = LLONG_MIN;
        /*
        out score is 
        score[i]= prefix[i] - suffmin[i];
        */
       for(int i=0;i<n-1;i++){
        ans = max(ans,(long long)(preSum[i]-suffMin[i+1]));
       }

       return ans;
    }
};