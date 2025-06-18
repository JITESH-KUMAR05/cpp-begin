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
    cout<<root->val << " ";
    inorder(root->right);
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    inorder(root);
    return 0;

}