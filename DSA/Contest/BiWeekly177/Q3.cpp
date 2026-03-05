// Q3. Minimum Operations to Make Array Parity Alternating
// Medium
// 5 pt.
// You are given an integer array nums.

// An array is called parity alternating if for every index i where 0 <= i < n - 1, nums[i] and nums[i + 1] have different parity (one is even and the other is odd).

// In one operation, you may choose any index i and either increase nums[i] by 1 or decrease nums[i] by 1.

// Return an integer array answer of length 2 where:

// answer[0] is the minimum number of operations required to make the array parity alternating.
// answer[1] is the minimum possible value of max(nums) - min(nums) taken over all arrays that are parity alternating and can be obtained by performing exactly answer[0] operations.
// An array of length 1 is considered parity alternating.

//  

// Example 1:

// Input: nums = [-2,-3,1,4]

// Output: [2,6]

// Explanation:

// Applying the following operations:

// Increase nums[2] by 1, resulting in nums = [-2, -3, 2, 4].
// Decrease nums[3] by 1, resulting in nums = [-2, -3, 2, 3].
// The resulting array is parity alternating, and the value of max(nums) - min(nums) = 3 - (-3) = 6 is the minimum possible among all parity alternating arrays obtainable using exactly 2 operations.

// Example 2:

// Input: nums = [0,2,-2]

// Output: [1,3]

// Explanation:

// Applying the following operation:

// Decrease nums[1] by 1, resulting in nums = [0, 1, -2].
// The resulting array is parity alternating, and the value of max(nums) - min(nums) = 1 - (-2) = 3 is the minimum possible among all parity alternating arrays obtainable using exactly 1 operation.

// Example 3:

// Input: nums = [7]

// Output: [0,0]

// Explanation:

// No operations are required. The array is already parity alternating, and the value of max(nums) - min(nums) = 7 - 7 = 0, which is the minimum possible.

//  

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> getResultForPattern(vector<int>& nums, int st) {
        int n = nums.size();
        int ops = 0;
        
        long long minn = 2e9, maxx = -2e9;
        vector<int> var;
        
        bool hasFixed = false;
        
        for(int i = 0; i < n; i++) {
            int targetParity = (st + i) % 2;
            // for negative number
            int currentParity = abs(nums[i]) % 2; 
            
            if(currentParity == targetParity) {
                hasFixed = true;
                if(nums[i] < minn) minn = nums[i];
                if(nums[i] > maxx) maxx = nums[i];
            } else {
                
                ops++;
                var.push_back(nums[i]);
            }
        }
        
        
        if(ops == 0) {
            int mn = nums[0], mx = nums[0];
            for(int x : nums) {
                mn = min(mn, x);
                mx = max(mx, x);
            }
            return {0, mx - mn};
        }
        
        if(var.empty()) {
           
            return {ops, (int)(maxx - minn)};
        }

        sort(var.begin(), var.end());
        
        int minRange = 2e9;
        int m = var.size();
      
        for(int i = -1; i < m; i++) {
            long long curMax = -2e9;
            long long curMin = 2e9;
            
            if (hasFixed) {
                curMax = maxx;
                curMin = minn;
            }
           
            if (i >= 0) {
                curMax = max(curMax, (long long)var[i] + 1);
                curMin = min(curMin, (long long)var[0] + 1);
            }
            
            if (i + 1 < m) {
                curMax = max(curMax, (long long)var[m-1] - 1);
                curMin = min(curMin, (long long)var[i+1] - 1);
            }
            
            if(curMax >= curMin) {
                minRange = min((long long)minRange, curMax - curMin);
            }
        }
        
        return {ops, minRange};
    }

    vector<int> makeParityAlternating(vector<int>& nums) {
        // Even, Odd, Even, Odd. so we can start from 0
        pair<int, int> resA = getResultForPattern(nums, 0);
        
        // Odd, Even, Odd, Even.. now start with 1
        pair<int, int> resB = getResultForPattern(nums, 1);
        
        if (resA.first < resB.first) {
            return {resA.first, resA.second};
        } else if (resB.first < resA.first) {
            return {resB.first, resB.second};
        } else {
            return {resA.first, min(resA.second, resB.second)};
        }
    }
};