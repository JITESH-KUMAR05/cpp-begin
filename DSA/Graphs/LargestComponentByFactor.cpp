// 952. Largest Component Size by Common Factor

// You are given an integer array of unique positive integers nums. Consider the following graph:

// There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
// There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
// Return the size of the largest connected component in the graph.

 

// Example 1:


// Input: nums = [4,6,15,35]
// Output: 4
// Example 2:


// Input: nums = [20,50,9,63]
// Output: 2
// Example 3:


// Input: nums = [2,3,6,7,4,12,21,39]
// Output: 8
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// 1 <= nums[i] <= 105
// All the values of nums are unique.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findparent(int node,vector<int>&parent){
        if(parent[node]==node) return node;
        return parent[node]=findparent(parent[node],parent);
    }

    void dounion(int u,int v,vector<int>&parent,vector<int>&size){
        int lu=findparent(u,parent);
        int lv=findparent(v,parent);
        if(lu==lv) return;
        if(size[lu]>size[lv]){
            size[lu]+=size[lv];
            parent[lv]=lu;
        }else{
            size[lv]+=size[lu];
            parent[lu]=lv;
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        vector<int>parent(100001);
        iota(parent.begin(),parent.end(),0);
        vector<int>size(100001,1);
        for(int num:nums){
            for(int i=2;i*i<=num;i++){
                if(num%i==0){
                    dounion(i,num,parent,size);
                    dounion(num,num/i,parent,size);
                }
            }
        }
        int cnt=0;
        unordered_map<int,int>freq;
        for(int num:nums){
            int root=findparent(num,parent);
            freq[root]++;
            cnt = max(cnt,freq[root]);
        }
        return cnt;
    }
};