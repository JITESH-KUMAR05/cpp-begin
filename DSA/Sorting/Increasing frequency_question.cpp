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
    unordered_map<int,int>first_appear;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(first_appear.find(arr[i]) == first_appear.end()){
            first_appear[arr[i]] = i;
        }
        freq[arr[i]]++;
    }
    
    // 2, 5, 2, 8, 5, 6, 8, 8 --> 
    // 0  1  2  3  4  5  6  7
    /* 
    this is the freq array
    {                           {
        2 : 2,                      2 : 0
        5 : 2,                      5 : 1
        8 : 3,                      8 : 3
        6 : 1                       6 : 5
                                }
    }
        now we can take one vector and store all the values the freq times and then sort it 
    */ 
   vector<int>unique;
   for(auto it:freq){
    unique.push_back(it.first);
   }
   sort(unique.begin(),unique.end(),[&](int a,int b){
    if(freq[a] != freq[b]){
        return freq[a] > freq[b];
    }
    return first_appear[a] < first_appear[b];
   });
   vector<int>res;
   for(int element : unique){
    int times = freq[element];
    for(int j=0;j<times;j++){
        res.push_back(element);
    }
   }
   for(int i=0;i<n;i++){
    cout << res[i] << " ";
   }
   cout << endl;   
    return 0;
}