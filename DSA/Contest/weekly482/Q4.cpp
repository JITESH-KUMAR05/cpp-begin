// Q4. Number of Balanced Integers in a Range
// Hard
// 7 pt.
// You are given two integers low and high.
// An integer is called balanced if it satisfies both of the following conditions:

// It contains at least two digits.
// The sum of digits at even positions is equal to the sum of digits at odd positions (the leftmost digit has position 1).
// Return an integer representing the number of balanced integers in the range [low, high] (both inclusive).

//  

// Example 1:

// Input: low = 1, high = 100

// Output: 9

// Explanation:

// The 9 balanced numbers between 1 and 100 are 11, 22, 33, 44, 55, 66, 77, 88, and 99.

// Example 2:

// Input: low = 120, high = 129

// Output: 1

// Explanation:

// Only 121 is balanced because the sum of digits at even and odd positions are both 2.

// Example 3:

// Input: low = 1234, high = 1234

// Output: 0

// Explanation:

// 1234 is not balanced because the sum of digits at odd positions (1 + 3 = 4) does not equal the sum at even positions (2 + 4 = 6).

//  

// Constraints:

// 1 <= low <= high <= 1015

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isbal(long long n){
        string s = to_string(n);
        if(s.length() < 2) return false;

        int oddsum = 0;
        int evensum = 0;
        for(int i=0;i<s.length();i++){
            int digit = s[i] - '0';
            if(i%2){
               evensum += digit; 
            }else{
                oddsum += digit;
            }
        }

        return oddsum == evensum;

    }
    long long countBalanced(long long low, long long high) {
        long long count = 0;
        for(long long i=low;i<=high;i++){
            if(isbal(i)){
                count++;
            }
        }

        return count;
    }
};