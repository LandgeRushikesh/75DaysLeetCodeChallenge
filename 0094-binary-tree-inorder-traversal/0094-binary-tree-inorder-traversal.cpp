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
    void inorderT(TreeNode* root,vector<int>& inorder){
       if(root==nullptr){
        return;
       }

       inorderT(root->left,inorder);
       inorder.push_back(root->val);
       inorderT(root->right,inorder);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        inorderT(root,inorder);
        return inorder;
    }
};