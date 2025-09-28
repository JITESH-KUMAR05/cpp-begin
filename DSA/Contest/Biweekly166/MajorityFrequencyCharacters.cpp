// 3692. Majority Frequency Characters

// You are given a string s consisting of lowercase English letters.

// The frequency group for a value k is the set of characters that appear exactly k times in s.

// The majority frequency group is the frequency group that contains the largest number of distinct characters.

// Return a string containing all characters in the majority frequency group, in any order. If two or more frequency groups tie for that largest size, pick the group whose frequency k is larger.

 

// Example 1:

// Input: s = "aaabbbccdddde"

// Output: "ab"

// Explanation:

// Frequency (k)	Distinct characters in group	Group size	Majority?
// 4	{d}	1	No
// 3	{a, b}	2	Yes
// 2	{c}	1	No
// 1	{e}	1	No
// Both characters 'a' and 'b' share the same frequency 3, they are in the majority frequency group. "ba" is also a valid answer.

// Example 2:

// Input: s = "abcd"

// Output: "abcd"

// Explanation:

// Frequency (k)	Distinct characters in group	Group size	Majority?
// 1	{a, b, c, d}	4	Yes
// All characters share the same frequency 1, they are all in the majority frequency group.

// Example 3:

// Input: s = "pfpfgi"

// Output: "fp"

// Explanation:

// Frequency (k)	Distinct characters in group	Group size	Majority?
// 2	{p, f}	2	Yes
// 1	{g, i}	2	No (tied size, lower frequency)
// Both characters 'p' and 'f' share the same frequency 2, they are in the majority frequency group. There is a tie in group size with frequency 1, but we pick the higher frequency: 2.

 

// Constraints:

// 1 <= s.length <= 100
// s consists only of lowercase English letters.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string majorityFrequencyGroup(string s) {
        /**
         * from this what can we understand is we need to return the string with 
         * highest frequency group wise let's try to debug 
         * for example s = "pfpfgi"
         *                  p - 2
         *                  f - 2
         *              so they got grouped together
         *                  g - 1
         *                  i - 1
         *              so they got grouped together 
         *      now the first group size is 2 and second group size is also 2 
         *      but the frequency of first group is greater than second so that is answer
         * 
        **/

        unordered_map<char,int>f1;
        for(char &ch:s){
            f1[ch]++; // here we are having the frequency of each char indivisually 
        }

        int maxifre = 0,maxsize=0; // we will find the maximum frequency and maxsize
        unordered_map<int,vector<char>>f2;
        for(auto &[ch,fre]:f1){
            f2[fre].push_back(ch); 
        }
        // 2 -> [p,f]
        vector<char>ans;
        for(auto &[fre,vec]:f2){
            if(vec.size() > maxsize){
                maxifre = fre;
                ans = vec;
                maxsize= (int)vec.size();
            }
            else if(vec.size()==maxsize){
                if(maxifre < fre){
                    maxifre = fre;
                    ans = vec;
                }
            }
        }
        string res="";
        for(char ch:ans){
            res += ch;
        }
        return res;
    }
};