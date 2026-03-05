// Q2. Check Digitorial Permutation
// Medium
// 4 pt.
// You are given an integer n.

// A number is called digitorial if the sum of the factorials of its digits is equal to the number itself.

// Determine whether any permutation of n (including the original order) forms a digitorial number.

// Return true if such a permutation exists, otherwise return false.

// Note:

// The factorial of a non-negative integer x, denoted as x!, is the product of all positive integers less than or equal to x, and 0! = 1.
// A permutation is a rearrangement of all the digits of a number that does not start with zero. Any arrangement starting with zero is invalid.
//  

// Example 1:

// Input: n = 145

// Output: true

// Explanation:

// The number 145 itself is digitorial since 1! + 4! + 5! = 1 + 24 + 120 = 145. Thus, the answer is true.

// Example 2:

// Input: n = 10

// Output: false

// Explanation:​​​​​​​

// 10 is not digitorial since 1! + 0! = 2 is not equal to 10, and the permutation "01" is invalid because it starts with zero.

//  

// Constraints:

// // 1 <= n <= 109

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getFact(int n){
        if(n <= 1) return 1;
        long long res = 1;
        for(int i=2;i<=n;i++){
            res *= i;
        }
        return res;
    }
    vector<long long> generateFacts(){
        vector<long long>facts;
        for(int i=0;i<=9;i++){
            facts.push_back(getFact(i));

        }
        return facts;
    }
    bool isDigitorialPermutation(int n) {
        vector<long long>facts = generateFacts();
        long long sf = 0;
        string strn = to_string(n);
        for(char c:strn){
            int digit = c-'0';
            sf += (facts[digit]);
        }

        string strSum = to_string(sf);

        if(strn.length() != strSum.length()){
            return false;
        }

        sort(strn.begin(),strn.end());
        sort(strSum.begin(),strSum.end());

        return strn == strSum;
    }
};