// 1792. Maximum Average Pass Ratio
// Medium
// There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

// You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

// The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

// Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:

// Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
// Output: 0.78333
// Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
// Example 2:

// Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
// Output: 0.53485
 

// Constraints:

// 1 <= classes.length <= 105
// classes[i].length == 2
// 1 <= passi <= totali <= 105
// 1 <= extraStudents <= 105

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        vector<int>prefixNum(n);
        vector<int>prefixDen(n);
        double ans = (double)(classes[0][0] / classes[0][1]);
        prefixNum[0]=classes[0][0];
        prefixDen[0]=classes[0][1];
        for(int i=1;i<n;i++){
            ans += (double)(classes[i][0] / classes[i][1]);
            prefixNum[i]=prefixNum[i-1]+classes[i][0];
            prefixDen[i]=prefixDen[i-1]+classes[i][1];
        }
        double maxi = ans;
        for(int i=0;i<n;i++){
            ans -= (double)(prefixNum[i] / prefixDen[i]);
            double newpass = (double)(classes[i][0] + extraStudents) / (classes[i][1] + extraStudents);
            ans += newpass;
            maxi = max(maxi, ans);
        }
        return maxi/n;
    }
};