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
    int FindHeight(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        return 1+max(FindHeight(root->left),FindHeight(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }

        int lt = FindHeight(root->left);
        int rt = FindHeight(root->right);

        if(abs(lt-rt)>1){
            return false;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right){
            return false;
        }

        return true;

    }
};