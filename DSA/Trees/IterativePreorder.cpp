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

vector<int>preorder(TreeNode* root){
    vector<int>pre;
    if(root==nullptr) return pre;
    stack<TreeNode *>st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        pre.push_back(root->val);
        if(root->right!=nullptr){
            st.push(root->right);
        }
        if(root->left!=nullptr){
            st.push(root->left);
        }
    }
    for(int i=0;i<pre.size();i++){
        cout << pre[i] << " ";
    }
    cout << endl;
    return pre;
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    preorder(root);
    return 0;

}