// Problem Title: Level Order Traversal of Binary Tree

// Problem Description:
// You are given a binary tree. Write a function to perform a level order traversal and return the elements in the order they are visited.

// Input:
// The input consists of nodes of a binary tree. Each node is represented as follows:
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// Output:
// Return a vector of vectors of integers. Each inner vector represents the elements in a level of the tree. The order of levels should be from top to bottom, left to right.
// Just complete the function vector<vector<int>> levelOrder(TreeNode* root);

// Constraints:
// 0<=Number of nodes in the tree<=100002

// Example:
// Input:
//        3
//       / \
//      9   20
//         /  \
//        15   7
// Output:
// [[3],[9, 20],[15, 7]]

// Note:
// In the example, the level order traversal of the given binary tree visits nodes level by level, from top to bottom, left to right.


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
    if(tc.size()==0){
        return NULL;
    }
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

//Do not edit the below lines of code

// vector<vector<int>>func(TreeNode* root){  
//     vector<vector<int>>res;
//     queue<TreeNode*>q;
//     q.push(root);
//     while(!q.empty()){
//         TreeNode * temp = q.front();
//         q.pop();
//         res.push_back(temp->val);
//         if(temp->left){
//             q.push(temp->left);
//         }
//         if(temp->right){
//             q.push(temp->right);
//         }
//     }
//     return res;
// }

vector<vector<int>>func(TreeNode* root){  
    vector<vector<int>>res;
    if(root==nullptr) return res;
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty()){
        int n=q.size();
        vector<int>level;
        for(int i=0;i<n;i++){
            TreeNode* temp=q.front();
            q.pop();
            level.push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }            
        }
        res.push_back(level);
    }
    return res;
}

//Do not edit the below lines of code

int main() {
    int n;
    cin>>n;
    int tcsize;
    cin>>tcsize;
    vector<int>testcase(tcsize);
    for(int i=0;i<tcsize;i++){
        cin>>testcase[i];
    }
    
    TreeNode* root=convert(testcase);
    
    vector<vector<int>>result=func(root);
    
    cout<<"[";
    for(int i=0;i<result.size();i++){
        cout<<"[";
        for(int j=0;j<result[i].size();j++){
            if(j<result[i].size()-1){
            cout<<result[i][j]<<",";
            }
            else{
                cout<<result[i][j];
            }
        }
        cout<<"]";
        if(i!=result.size()-1){
            cout<<",";
        }
    }
    cout<<"]";
    return 0;
}