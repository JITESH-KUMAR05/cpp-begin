// Q3. Maximum Bitwise XOR After Rearrangement
// Medium
// 5 pt.
// You are given two binary strings s and t​​​​​​​, each of length n.

// You may rearrange the characters of t in any order, but s must remain unchanged.

// Return a binary string of length n representing the maximum integer value obtainable by taking the bitwise XOR of s and rearranged t.

//  

// Example 1:

// Input: s = "101", t = "011"

// Output: "110"

// Explanation:

// One optimal rearrangement of t is "011".
// The bitwise XOR of s and rearranged t is "101" XOR "011" = "110", which is the maximum possible.
// Example 2:

// Input: s = "0110", t = "1110"

// Output: "1101"

// Explanation:

// One optimal rearrangement of t is "1011".
// The bitwise XOR of s and rearranged t is "0110" XOR "1011" = "1101", which is the maximum possible.
// Example 3:

// Input: s = "0101", t = "1001"

// Output: "1111"

// Explanation:

// One optimal rearrangement of t is "1010".
// The bitwise XOR of s and rearranged t is "0101" XOR "1010" = "1111", which is the maximum possible.
//  

// Constraints:

// 1 <= n == s.length == t.length <= 2 * 105
// s[i] and t[i] are either '0' or '1'.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.length();

        int cnt1 = 0;

        for(char c:t){
            if(c=='1') cnt1++;
        }
        int cnt0 = n - cnt1;

        string res = "";

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(cnt0 > 0){
                    res+='1';
                    cnt0--;
                }else{
                    res+='0';
                    cnt1--;
                }
            }else{
                if(cnt1>0){
                    res+='1';
                    cnt1--;
                }else{
                    res+='0';
                    cnt0--;
                }
            }
        }
        return res;
    }
};