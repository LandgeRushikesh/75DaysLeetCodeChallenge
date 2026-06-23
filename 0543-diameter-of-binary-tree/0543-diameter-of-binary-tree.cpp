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
// Brute Force Approach
/*
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
*/

/*
Time Complexity - O(N^2)

Space Complexity - O(N)
*/


// Optimal Approach

    int FindMaxDia(TreeNode* root,int &maxDia){
        if(root==nullptr){
            return 0;
        }

        int ltHeight = FindMaxDia(root->left,maxDia);
        int rtHeight = FindMaxDia(root->right,maxDia);

        maxDia = max(maxDia,ltHeight+rtHeight);

        return 1+ max(ltHeight,rtHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        FindMaxDia(root,maxDia);
        return maxDia;
    }
};