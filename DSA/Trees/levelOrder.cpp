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
/*
for level order we need one data structure to store the result and one queue for maintaining 
the current level by which we can check all the childer of the current level 
if children exist then we will add the children into the level vector and then
add the level vector to the result vector after checking all the childrent on the current level 
also one more note that initially we should add the root to the queue inorder algo to work properly
now we have one variation that in the part two then we can just reverse at the end and then return 
*/

void levelOrder(TreeNode *root){
    vector<vector<int>>ans;
    if(root==nullptr) return;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            TreeNode * node = q.front();
            q.pop();
            if(node->left != nullptr){
                q.push(node->left);
            }
            if(node->right!=nullptr){
                q.push(node->right);
            }
            cout << node->val << " ";
            level.push_back(node->val);
        }
        cout << endl;
        ans.push_back(level);
    }

}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    levelOrder(root);
    return 0;

}