// 3784. Minimum Deletion Cost to Make All Characters Equal
// Medium
// premium lock icon
// Companies
// Hint
// You are given a string s of length n and an integer array cost of the same length, where cost[i] is the cost to delete the ith character of s.

// You may delete any number of characters from s (possibly none), such that the resulting string is non-empty and consists of equal characters.

// Return an integer denoting the minimum total deletion cost required.

 

// Example 1:

// Input: s = "aabaac", cost = [1,2,3,4,1,10]

// Output: 11

// Explanation:

// Deleting the characters at indices 0, 1, 2, 3, 4 results in the string "c", which consists of equal characters, and the total cost is cost[0] + cost[1] + cost[2] + cost[3] + cost[4] = 1 + 2 + 3 + 4 + 1 = 11.

// Example 2:

// Input: s = "abc", cost = [10,5,8]

// Output: 13

// Explanation:

// Deleting the characters at indices 1 and 2 results in the string "a", which consists of equal characters, and the total cost is cost[1] + cost[2] = 5 + 8 = 13.

// Example 3:

// Input: s = "zzzzz", cost = [67,67,67,67,67]

// Output: 0

// Explanation:

// All characters in s are equal, so the deletion cost is 0.

 

// Constraints:

// n == s.length == cost.length
// 1 <= n <= 105
// 1 <= cost[i] <= 109
// s consists of lowercase English letters.

#include<bits/stdc++.h>
using namespace std;
// this code is accepted 
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n = cost.size();
        unordered_map<int,long long>mp;
        for(int i=0;i<n;i++){
            mp[s[i]] += cost[i];
        }
        long long sm = 0;
        long long maxi = 0;
        for(auto &p:mp){
            sm += p.second;
            if(p.second > maxi){
                maxi = p.second;
            }
        }
        return sm - maxi;
    }
};