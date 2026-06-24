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
    bool pathSum(TreeNode* root, int remainingTarget){
        if(root==nullptr){
            return false;
        }

        remainingTarget -= root->val;

        if(root->left==nullptr && root->right==nullptr){
            return remainingTarget==0;
        }

        bool lt = pathSum(root->left,remainingTarget);
        bool rt = pathSum(root->right,remainingTarget);

        return lt || rt;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathSum(root,targetSum);
    }
};