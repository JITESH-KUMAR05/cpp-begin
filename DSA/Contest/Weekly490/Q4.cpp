// Q4. Count Sequences to K
// Hard
// 6 pt.
// You are given an integer array nums, and an integer k.
// Start with an initial value val = 1 and process nums from left to right. At each index i, you must choose exactly one of the following actions:

// Multiply val by nums[i].
// Divide val by nums[i].
// Leave val unchanged.
// After processing all elements, val is considered equal to k only if its final rational value exactly equals k.

// Return the count of distinct sequences of choices that result in val == k.

// Note: Division is rational (exact), not integer division. For example, 2 / 4 = 1 / 2.

//  

// Example 1:

// Input: nums = [2,3,2], k = 6

// Output: 2

// Explanation:

// The following 2 distinct sequences of choices result in val == k:

// Sequence	Operation on nums[0]	Operation on nums[1]	Operation on nums[2]	Final val
// 1	Multiply: val = 1 * 2 = 2	Multiply: val = 2 * 3 = 6	Leave val unchanged	6
// 2	Leave val unchanged	Multiply: val = 1 * 3 = 3	Multiply: val = 3 * 2 = 6	6
// Example 2:

// Input: nums = [4,6,3], k = 2

// Output: 2

// Explanation:

// The following 2 distinct sequences of choices result in val == k:

// Sequence	Operation on nums[0]	Operation on nums[1]	Operation on nums[2]	Final val
// 1	Multiply: val = 1 * 4 = 4	Divide: val = 4 / 6 = 2 / 3	Multiply: val = (2 / 3) * 3 = 2	2
// 2	Leave val unchanged	Multiply: val = 1 * 6 = 6	Divide: val = 6 / 3 = 2	2
// Example 3:

// Input: nums = [1,5], k = 1

// Output: 3

// Explanation:

// The following 3 distinct sequences of choices result in val == k:

// Sequence	Operation on nums[0]	Operation on nums[1]	Final val
// 1	Multiply: val = 1 * 1 = 1	Leave val unchanged	1
// 2	Divide: val = 1 / 1 = 1	Leave val unchanged	1
// 3	Leave val unchanged	Leave val unchanged	1
//  

// Constraints:

// 1 <= nums.length <= 19
// 1 <= nums[i] <= 6
// 1 <= k <= 1015

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<long long, long long> simplify(long long num, long long den) {
        if (num == 0) return {0, 1};
        long long common = __gcd(abs(num), abs(den));
        return {num / common, den / common};
    }

   
    void generate(int idx, int end, const vector<int>& nums, 
                 long long currentNum, long long currentDen, 
                 map<pair<long long, long long>, int>& results) {
        
        if (idx == end) {
            pair<long long, long long> val = simplify(currentNum, currentDen);
            results[val]++;
            return;
        }

        // Option 1: Multiply
        generate(idx + 1, end, nums, currentNum * nums[idx], currentDen, results);

        // Option 2: Divide
        generate(idx + 1, end, nums, currentNum, currentDen * nums[idx], results);

        // Option 3: Unchanged
        generate(idx + 1, end, nums, currentNum, currentDen, results);
    }

    int countSequences(vector<int>& nums, long long k) {
        int n = nums.size();
        int mid = n / 2;

        map<pair<long long, long long>, int> leftMap;
        
        generate(0, mid, nums, 1, 1, leftMap);

        map<pair<long long, long long>, int> rightMap;
        
        generate(mid, n, nums, 1, 1, rightMap);

        long long totalCount = 0;

        for (auto const& [rightVal, rightCount] : rightMap) {
            long long Rn = rightVal.first;
            long long Rd = rightVal.second;

            if (Rn == 0) continue; 
            
            __int128_t numerator = (__int128_t)k * Rd;
            __int128_t denominator = Rn;
            
            __int128_t common = __gcd(numerator < 0 ? -numerator : numerator, 
                                      denominator < 0 ? -denominator : denominator);
            
            numerator /= common;
            denominator /= common;

            pair<long long, long long> target = {(long long)numerator, (long long)denominator};

            if (leftMap.count(target)) {
                totalCount += (long long)rightCount * leftMap[target];
            }
        }

        return totalCount;
    }
    
    __int128_t __gcd(__int128_t a, __int128_t b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
};