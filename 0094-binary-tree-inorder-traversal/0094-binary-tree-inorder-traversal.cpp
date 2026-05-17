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
    // void inorderT(TreeNode* root,vector<int>& inorder){
    //    if(root==nullptr){
    //     return;
    //    }

    //    inorderT(root->left,inorder);
    //    inorder.push_back(root->val);
    //    inorderT(root->right,inorder);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> inorder;
    //     inorderT(root,inorder);
    //     return inorder;
    // }
    /*
    Time Complexity - O(n)

    Space Complexity - O(h)
    */

    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<int> inorder;
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while(curr != nullptr || !st.empty()){

            // Go to leftmost node
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }

            // Process node
            curr = st.top();
            st.pop();

            inorder.push_back(curr->val);

            // Move to right subtree
            curr = curr->right;
        }


        return inorder;
    }
};