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

        return 1 + max(FindHeight(root->left),FindHeight(root->right));
    }
    void FindMaxDia(TreeNode* root,int &maxDia){
        if(root==nullptr){
            return ;
        }

        int ltHeight = FindHeight(root->left);
        int rtHeight = FindHeight(root->right);

        maxDia = max(maxDia,ltHeight+rtHeight);
        FindMaxDia(root->left,maxDia);
        FindMaxDia(root->right,maxDia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        FindMaxDia(root,maxDia);
        return maxDia;
    }
};