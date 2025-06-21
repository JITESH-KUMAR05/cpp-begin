// Problem Statement:

// Given an integer N, which denotes the size of a subset containing N elements. Find the number of ways in which the given set of size N can be divided into subsets.

// Examples:

// Input:  n = 2

// Output: Number of ways = 2

// Explanation: Let the set be {1, 2}

// Subsets will be: {{1},{2}}, {{1, 2}}

// Constraint:

// 1 <= n <= 10

//3 
//[1,2,3] 
//how many ways you can break this array in some subset configration 

// [{1,3},{2}] , [{1},{2,3}] , [{1,2,3}], [{1},{2},{3}] ,  [{1,2}, {3}]


//lets say i reach an index i and I am maintaining subsets taken till now like s1 s2 
//then how many options do I have for current element?

#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>>result;
void dfs(int inx,int n,vector<vector<int>>&current){
    if(inx==n+1){
        result.push_back(current);
        return;
    }
    //we have option to put this element in all the subsets existing also we can start new subset for this
    for(int i=0;i<current.size();i++){
        current[i].push_back(inx);
        dfs(inx+1,n,current);
        current[i].pop_back();
    }
    vector<int>temp;  //starting  a new subset from this element 
    temp.push_back(inx);
    current.push_back(temp);
    dfs(inx+1,n,current);
    current.pop_back();
    return;
}
int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>>current;
    dfs(1,n,current);
    for(int i=0;i<result.size();i++){
        vector<vector<int>>possible_config=result[i];
        for(int j=0;j<possible_config.size();j++){
            for(int k=0;k<possible_config[j].size();k++){
                cout<<possible_config[j][k]<<" ";
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}