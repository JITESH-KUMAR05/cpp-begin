#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int data){
        val = data;
        left=nullptr;
        right=nullptr;
    }
};

void inorder(TreeNode * root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->val;
    inorder(root->right);
}

int main(){
    TreeNode * root = new TreeNode(1);
    
}