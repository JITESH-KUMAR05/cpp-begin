// Q2. Minimum Cost to Acquire Required Items
// Medium
// 5 pt.
// You are given five integers cost1, cost2, costBoth, need1, and need2.

// There are three types of items available:

// An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
// An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
// An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.
// You must collect enough items so that the total contribution toward type 1 is at least need1 and the total contribution toward type 2 is at least need2.

// Return an integer representing the minimum possible total cost to achieve these requirements.

//  

// Example 1:

// Input: cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2

// Output: 3

// Explanation:

// After buying three type 3 items, which cost 3 * 1 = 3, the total contribution to type 1 is 3 (>= need1 = 3) and to type 2 is 3 (>= need2 = 2).
// Any other valid combination would cost more, so the minimum total cost is 3.

// Example 2:

// Input: cost1 = 5, cost2 = 4, costBoth = 15, need1 = 2, need2 = 3

// Output: 22

// Explanation:

// We buy need1 = 2 items of type 1 and need2 = 3 items of type 2: 2 * 5 + 3 * 4 = 10 + 12 = 22.
// Any other valid combination would cost more, so the minimum total cost is 22.

// Example 3:

// Input: cost1 = 5, cost2 = 4, costBoth = 15, need1 = 0, need2 = 0

// Output: 0

// Explanation:

// Since no items are required (need1 = need2 = 0), we buy nothing and pay 0.

//  

// Constraints:

// 1 <= cost1, cost2, costBoth <= 106
// 0 <= need1, need2 <= 109


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        /*
        we have 2 options only right 
        that whatever the need is we can take with the help of indivisuals or directly too
        but this will not work when one cost is very low and other is very high then the both will be less
        */

        ll c1 = cost1;
        ll c2 = cost2;
        ll cb = costBoth;
        ll n1 = need1;
        ll n2 = need2;


        ll op1 = (n1 * c1) + (n2 * c2);

        ll min_need = min(n1, n2);
        ll remaining_n1 = n1 - min_need;
        ll remaining_n2 = n2 - min_need;

        ll op2 = (min_need * cb) + (remaining_n1 * c1) + (remaining_n2 * c2);

        ll max_need = max(n1, n2);
        ll op3 = max_need * cb;

        return min({op1, op2, op3});
    }
};