// 1373. Maximum Sum BST in Binary Tree
// Hard
// Topics
// premium lock iconCompanies
// Hint

// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

// Assume a BST is defined as follows:

//     The left subtree of a node contains only nodes with keys less than the node's key.
//     The right subtree of a node contains only nodes with keys greater than the node's key.
//     Both the left and right subtrees must also be binary search trees.

// Example 1:

// Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
// Output: 20
// Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.

// Example 2:

// Input: root = [4,3,null,1,2]
// Output: 2
// Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.

// Example 3:

// Input: root = [-4,-2,-5]
// Output: 0
// Explanation: All values are negatives. Return an empty BST.

// Constraints:

//     The number of nodes in the tree is in the range [1, 4 * 104].
//     -4 * 104 <= Node.val <= 4 * 104

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// we are taking arr in the form 
// it will contain 
// bool , min , max , sum
//  0      1     2     3

class Solution
{
public:
    vector<long long> checkBST(TreeNode *node, long long &ans)
    {
        if(!node){
            return {true,LLONG_MAX,LLONG_MIN,0};
        }
        if (node->left == nullptr && node->right == nullptr)
        {
            ans = max(ans,(long long) node->val);
            return {true, node->val, node->val, node->val};
        }

        if (node->left == nullptr)
        {
            vector<long long> rt = checkBST(node->right, ans);
            if (rt[0] && node->val < rt[1])
            {
                long long sum = node->val + rt[3];
                ans = max(ans, sum);
                return {true, min((long long)node->val,rt[1]), max((long long)node->val,rt[2]), sum};
            }
            else
            {
                return {false, -1, -1, -1};
            }
        }
        if(node->right==nullptr){
            vector<long long>lt=checkBST(node->left,ans);
            if(lt[0] && node->val > lt[2]){
                long long sum = node->val+lt[3];
                ans=max(ans,sum);
                return {true,min((long long)node->val,lt[1]),max((long long)node->val,lt[2]),sum};
            }else{
                return {false,-1,-1,-1};
            }
        }

        if(node->left && node->right){
            vector<long long>lt=checkBST(node->left,ans);
            vector<long long>rt=checkBST(node->right,ans);
            if(lt[0]==false || rt[0]==false){
                return {false,-1,-1,-1};
            }
            if(node->val > lt[2] && node->val < rt[1]){
                long long sum = lt[3] + rt[3] + node->val;
                ans = max(ans,sum);
                return {true,min((long long)node->val,lt[1]),max((long long)node->val,rt[2]),sum};
            }
            else{
                return {false,-1,-1,-1};
            }
        }
        return {false,0,0,0};
    }
    int maxSumBST(TreeNode *root)
    {
        long long maxsum = 0;
        checkBST(root,maxsum);
        return maxsum;
    }
};