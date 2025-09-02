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

// This will give TLE and MLE

// class Solution {
// public:
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
//         int n = classes.size();
//         vector<double>PR(n);
//         for(int i=0;i<n;i++){
//             double ratio = (double)classes[i][0]/classes[i][1];
//             PR[i]=ratio;
//         }

//         while(extraStudents--){

//             vector<double>updatedPR(n);
//             for(int i=0;i<n;i++){
//                 double ratio=(double)(classes[i][0]+1)/(classes[i][1]+1);
//                 updatedPR[i]=ratio;
//             }

//             double maxdiff=0.0;
//             int maxdiffId=0;
//             for(int i=0;i<n;i++){
//                 double diff = abs(PR[i]-updatedPR[i]);
//                 if(diff>maxdiff){
//                     maxdiff=diff;
//                     maxdiffId=i;
//                 }
//             }
//             PR[maxdiffId]=updatedPR[maxdiffId];
//             classes[maxdiffId][0]++;
//             classes[maxdiffId][1]++;
//         }
//         double avg = 0.0;
//         for(int i=0;i<n;i++){
//             avg += (double)classes[i][0]/classes[i][1];
//         }
//         avg = avg / n;
//         return avg;
//     }
// };

class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<P> pq;

        for(int i=0;i<n;i++){
            double currentratio = (double)classes[i][0]/classes[i][1];
            double newratio = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double diff = abs(newratio - currentratio);
            pq.push({diff,i});
        }
        while(extraStudents--){
            auto curr = pq.top();
            pq.pop();

            double diff = curr.first;
            double idx = curr.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double currentratio = (double)classes[idx][0]/classes[idx][1];
            double newratio = (double)(classes[idx][0]+1)/(classes[idx][1]+1);
            double newdiff = abs(newratio-currentratio);

            pq.push({newdiff,idx});
        }
        double res=0.0;
        for(int i=0;i<n;i++){
            res += (double)classes[i][0]/classes[i][1];
        }
        return res/n;
    }
};