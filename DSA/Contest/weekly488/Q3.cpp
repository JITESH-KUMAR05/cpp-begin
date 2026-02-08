// Q3. Count Subarrays With Cost Less Than or Equal to K
// Medium
// 5 pt.
// You are given an integer array nums, and an integer k.

// For any subarray nums[l..r], define its cost as:

// cost = (max(nums[l..r]) - min(nums[l..r])) * (r - l + 1).

// Return an integer denoting the number of subarrays of nums whose cost is less than or equal to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

//  

// Example 1:

// Input: nums = [1,3,2], k = 4

// Output: 5

// Explanation:

// We consider all subarrays of nums:

// nums[0..0]: cost = (1 - 1) * 1 = 0
// nums[0..1]: cost = (3 - 1) * 2 = 4
// nums[0..2]: cost = (3 - 1) * 3 = 6
// nums[1..1]: cost = (3 - 3) * 1 = 0
// nums[1..2]: cost = (3 - 2) * 2 = 2
// nums[2..2]: cost = (2 - 2) * 1 = 0
// There are 5 subarrays whose cost is less than or equal to 4.

// Example 2:

// Input: nums = [5,5,5,5], k = 0

// Output: 10

// Explanation:

// For any subarray of nums, the maximum and minimum values are the same, so the cost is always 0.

// As a result, every subarray of nums has cost less than or equal to 0.

// For an array of length 4, the total number of subarrays is (4 * 5) / 2 = 10.

// Example 3:

// Input: nums = [1,2,3], k = 0

// Output: 3

// Explanation:

// The only subarrays of nums with cost 0 are the single-element subarrays, and there are 3 of them.

//  

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 0 <= k <= 1015

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    long long countSubarrays(vector<int>& nums, long long k) {
        ll count = 0; 
        int n = nums.size();

        // now we need to two deque to store the max and min indices;
        deque<int>maxi;
        deque<int>mini;
        int l = 0;

        for(int r=0;r<n;r++){
            while(!maxi.empty() && nums[maxi.back()] <= nums[r]){
                maxi.pop_back();
            }
            maxi.push_back(r);

            while(!mini.empty() && nums[mini.back()] >= nums[r]){
                mini.pop_back();
            }
            mini.push_back(r);


            while(true){
                ll currMax = nums[maxi.front()];
                ll currMin = nums[mini.front()];
                ll len = r-l+1;

                ll cost = (currMax - currMin) * len;

                if(cost > k){
                    l++;
                    if(!maxi.empty() && maxi.front() < l){
                        maxi.pop_front();

                    }
                    if(!mini.empty() && mini.front() < l){
                        mini.pop_front();
                    }
                }else{
                    break;
                }
            }
            count += (r-l+1);

        }
        return count;
    }
};