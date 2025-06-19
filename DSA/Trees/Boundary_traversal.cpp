/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node * root){
        if(!root->left && !root->right){
            return true;
        }
        return false;
    }
    void addLeftBoundary(Node* root,vector<int>&res){
        Node* cur = root->left;
        while(cur){
            if(!isLeaf(cur)) res.push_back(cur->data);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }
    void addRightBoundary(Node* root,vector<int>&res){
        Node * cur = root->right;
        stack<int>st;
        while(cur){
            if(!isLeaf(cur)) st.push(cur->data);
            if(cur->right)cur = cur->right;
            else cur = cur->left;
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
    }
    void addLeaf(Node * root,vector<int>&res){
        if(isLeaf(root)){
        res.push_back(root->data);
        return;
        }
        if(root->left) addLeaf(root->left,res);
        if(root->right) addLeaf(root->right,res);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root,res);
        addLeaf(root,res);
        addRightBoundary(root,res);
        return res;
    }
};