/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preOrderT(TreeNode* root,vector<int> &preorder){
       if(root==nullptr){
        return;
       }

       preorder.push_back(root->val);
       preOrderT(root->left,preorder);
       preOrderT(root->right,preorder);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        preOrderT(root,preorder);
        return preorder;
        
    }
    /*
    Time Complexity - O(n)--->each node visited only once

    Space Complexity - O(h)--->recursion stack h=height of the tree
    */
};