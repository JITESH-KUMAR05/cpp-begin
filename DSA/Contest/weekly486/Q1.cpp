// Q1. Minimum Prefix Removal to Make Array Strictly Increasing
// Medium
// 4 pt.
// You are given an integer array nums.

// You need to remove exactly one prefix (possibly empty) from nums.

// Return an integer denoting the minimum length of the removed prefix such that the remaining array is strictly increasing.

// A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.

// An array is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

//  

// Example 1:

// Input: nums = [1,-1,2,3,3,4,5]

// Output: 4

// Explanation:

// Removing the prefix = [1, -1, 2, 3] leaves the remaining array [3, 4, 5] which is strictly increasing.

// Example 2:

// Input: nums = [4,3,-2,-5]

// Output: 3

// Explanation:

// Removing the prefix = [4, 3, -2] leaves the remaining array [-5] which is strictly increasing.

// Example 3:

// Input: nums = [1,2,3,4]

// Output: 0

// Explanation:

// The array nums = [1, 2, 3, 4] is already strictly increasing so removing an empty prefix is sufficient.

//  

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        // we will start from end of the array and then find the first index where the condition fails 
        //  nums = [1,-1,2,3,3,4,5]
            //                 i i+1
        int id = -1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] >= nums[i+1]){
                id=i;
                break;
            }
        }
        return id+1;

    }
};