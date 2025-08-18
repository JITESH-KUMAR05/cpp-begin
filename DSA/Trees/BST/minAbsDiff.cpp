// 530. Minimum Absolute Difference in BST
// Easy
// Topics
// premium lock icon
// Companies
// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

// Example 1:


// Input: root = [4,2,6,1,3]
// Output: 1
// Example 2:


// Input: root = [1,0,48,null,null,12,49]
// Output: 1
 

// Constraints:

// The number of nodes in the tree is in the range [2, 104].
// 0 <= Node.val <= 105
 

// Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

#include<bits/stdc++.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int mindiff=INT_MAX;
    void dfs(TreeNode* root,TreeNode* &prev){
        if(root==nullptr) return;

        dfs(root->left,prev);
        if(prev!=nullptr){
            mindiff=min(mindiff,root->val-prev->val);

        }
        prev=root;
        dfs(root->right,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode *prev=nullptr;

        dfs(root,prev);

        return mindiff;
    }
};