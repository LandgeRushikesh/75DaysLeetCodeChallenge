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

    // Iterative Approach
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if(root==nullptr){
    //         return nullptr;
    //     }
    //     TreeNode* temp = root;
    //     while(temp!=nullptr){
    //         if(temp->val==val){
    //             return temp;
    //         }
    //         else if(temp->val>val){
    //             temp = temp->left;
    //         }
    //         else{
    //             temp = temp->right;
    //         }
    //     }

    //     return nullptr;
    // }

    // Recursive Approach 
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr || root->val == val){
            return root;
        }

        if(val < root->val){
            return searchBST(root->left, val);
        }

        return searchBST(root->right, val);
    }
};