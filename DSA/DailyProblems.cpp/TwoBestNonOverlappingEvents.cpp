// 2054. Two Best Non-Overlapping Events
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

// Return this maximum sum.

// Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

 

// Example 1:


// Input: events = [[1,3,2],[4,5,2],[2,4,3]]
// Output: 4
// Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
// Example 2:

// Example 1 Diagram
// Input: events = [[1,3,2],[4,5,2],[1,5,5]]
// Output: 5
// Explanation: Choose event 2 for a sum of 5.
// Example 3:


// Input: events = [[1,5,3],[1,5,1],[6,6,5]]
// Output: 8
// Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
 

// Constraints:

// 2 <= events.length <= 105
// events[i].length == 3
// 1 <= startTimei <= endTimei <= 109
// 1 <= valuei <= 106

#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int maxTwoEvents(vector<vector<int>>& events) {
//         // here what i am thinking is that we can take one heap(maxheap)
//         // we will store this data in the form which is 
//         // Heap<pair<int,pair<start,end>> 
//         //           value    start end 
//         //  then we will have the maximum value data on the top we can compare the 
//         // start and end values now and consider the value for our answer 
//         //  the condition will be like start value of next should be greater than
//         //  end value of the previous one 
//         // in this way we will be able to get the top 2 values which gives the 
//         // maximum answer 
//     }
// };


// The above approach will not work

/*
    for the example 
        Event A: [1, 10, 10] (Starts at 1, ends at 10, value is 10)
        Event B: [1, 4, 6] (Starts at 1, ends at 4, value is 6)
        Event C: [5, 10, 6] (Starts at 5, ends at 10, value is 6)

*/

// Let's thinking about something different 

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        
    }
};