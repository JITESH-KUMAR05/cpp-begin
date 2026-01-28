// 990. Satisfiability of Equality Equations
// Medium
// Topics
// premium lock icon
// Companies
// You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

// Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

 

// Example 1:

// Input: equations = ["a==b","b!=a"]
// Output: false
// Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
// There is no way to assign the variables to satisfy both equations.
// Example 2:

// Input: equations = ["b==a","a==b"]
// Output: true
// Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 

// Constraints:

// 1 <= equations.length <= 500
// equations[i].length == 4
// equations[i][0] is a lowercase letter.
// equations[i][1] is either '=' or '!'.
// equations[i][2] is '='.
// equations[i][3] is a lowercase letter.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
    void doUnion(int u,int v){
        int lu = find(u);
        int lv = find(v);
        if(lu==lv) return;
        if(rank[lu]>rank[lv]){
            parent[lv]=lu;
        }
        else if(rank[lv]>rank[lu]){
            parent[lu]=lv;
        }
        else{
            parent[lv]=lu;
            rank[lu]+=1;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);

        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(string &s:equations){
            if(s[1]=='='){
                doUnion(s[0]-'a',s[3]-'a');
            }

        }

        for(string &s:equations){
            if(s[1]=='!'){
                int u = s[0]-'a';
                int v = s[3]-'a';
                int lu = find(u);
                int lv = find(v);
                if(lu==lv) return false;
            }            
        }
        return true;
    }
};