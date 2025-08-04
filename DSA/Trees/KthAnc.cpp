// Problem Title: Kth Ancestor in Binary Tree

// Problem Description:

// You are given a binary tree of size N, a node with a positive integer value k. Your task is to complete the function kthAncestor(), which should return the k-th ancestor of the given node in the binary tree. If there does not exist any such ancestor, return -1.

// Input:
// The input consists of a binary tree with distinct node values, a specific node, and a positive integer k.
// Output:
// Return the value of the k-th ancestor of the given node.
// Just complete the function 
// int kthAncestor(TreeNode* root, int k, int nodeValue);

// Constraints:
// 1<=k<=100002
// 1<=Number of nodes in the tree<=100002

// Example:

// Input:
//        1
//       / \
//      2   3
//     / \
//    4   5
//   / \
//  6   7

// k = 3
// nodeValue = 7

// Output:
// 1
// Note:
// In the example, given the binary tree and node value 7, the 3rd ancestor is 1.


#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int val){
        this->val=val;
        left=NULL;
        right=NULL;
    }
};
TreeNode* convert(vector<int>&tc){   
     TreeNode* root=new TreeNode(tc[0]);
     int i=0;
     int j=1;
     vector<TreeNode*>tree;
     tree.push_back(root);
     while(j<tc.size()){
         if(tc[j]==-1){
             tree[i]->left=NULL;
         }
         else{
             tree[i]->left=new TreeNode(tc[j]);
             tree.push_back(tree[i]->left);
         }
         j++;
         if(j<tc.size()){
             if(tc[j]==-1){
                 tree[i]->right=NULL;
             }
             else{
                 tree[i]->right=new TreeNode(tc[j]);
                 tree.push_back(tree[i]->right);
             }
             j++;
         }
         i++;
     }
     return root;
 }

//Donot edit above lines of code

int solve(TreeNode *root,int k,int node,int ans){
    if(root==nullptr) return -1;
    if(root->val==node){
        return 0;
    }

    int leftVal=solve(root->left,k,node,ans);
    int rightVal=solve(root->right,k,node,ans);

    if(leftVal!=-1){
        int curdis = leftVal+1;
        if(curdis==k){
            ans = root->val;
        }
        return curdis;
    }
    if(rightVal!=-1){
        int curdis=rightVal+1;
        if(curdis==k){
            ans=root->val;

        }
        return curdis;
    }
    return -1;
}

int ancestor(TreeNode *root, int k, int node)
{
    int ans=-1;
    solve(root,k,node,ans);
    return ans;
}



//donot edit below lines of code
int main() {
    int n;
    cin>>n;
    int tcsize;
    cin>>tcsize;
    vector<int>testcase(tcsize);
    for(int i=0;i<tcsize;i++){
        cin>>testcase[i];
    }
    int k,node;
    cin>>k>>node;
    TreeNode* root=convert(testcase);
   int temp=ancestor(root,k,node);
   cout<<temp<<endl;
    return 0;
}

