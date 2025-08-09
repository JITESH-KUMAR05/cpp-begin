// 109. Convert Sorted List to Binary Search Tree
// Attempted
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

// Example 1:


// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
// Example 2:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in head is in the range [0, 2 * 104].
// -105 <= Node.val <= 105

#include<bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
 struct ListNode {
    int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
/**
 * Definition for a binary tree node.
 **/
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
    void converToArr(ListNode* head,vector<int>&arr){
        if(head==nullptr) return;
        while(head){
            arr.push_back(head->val);
            head=head->next;
        }
    }
    // TreeNode* SortedArrToBST(vector<int>&arr){
    //     int n=arr.size();
    //     if(n==0) return nullptr;
    //     n = n/2;
    //     int val=arr[n];
    //     TreeNode* root=new TreeNode(val);
    //     vector<int>lh(arr.begin(),arr.begin()+n);
    //     vector<int>rh(arr.begin()+n+1,arr.end());
    //     root->left=SortedArrToBST(lh);
    //     root->right=SortedArrToBST(rh);
    //     return root;
    // }
    TreeNode* SortedArrToBST(int l,int h,vector<int>&arr){
        if(l>h) return nullptr;
        int mid=l+(h-l)/2;
        int val=arr[mid];
        TreeNode *root=new TreeNode(val);
        root->left=SortedArrToBST(l,mid,arr);
        root->right=SortedArrToBST(mid+1,h,arr);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // first we will convert this list into an array and then from the array we can conver to bst
        vector<int>arr;
        converToArr(head,arr);
        // sort(arr.begin(),arr.end()); // as already sorted no need 
        
        // return SortedArrToBST(arr);
        return SortedArrToBST(0,arr.size(),arr);
    }
};