// Problem Statement:
// Print the elements of an array in the decreasing frequency if 2 numbers have the same frequency then print the one which came first
// Examples: 
// Input:  arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
// Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6}
// Constraint:
// 1 <= N <= 10000
// -10000 <= arr[i] <= 10000

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    unordered_map<int ,int>freq;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    
    // 2, 5, 2, 8, 5, 6, 8, 8 --> 
    /* {
        2 : 2,          
        5 : 2,
        8 : 3,
        6 : 1
    }
        now we can take one vector and store all the values the freq times and then sort it 
    */ 
   vector<int>res;
   for(auto &it:freq){
    int times = it.second;
    for(int j=0;j<times;j++){
        res.push_back(it.first);
    }
   }
   sort(res.begin(),res.end(),greater<int>());
   for(int i=0;i<n;i++){
    cout << res[i] << " ";
   }
   cout << endl;
    return 0;
}