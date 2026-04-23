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
    // Brute Force Approach -

    // void getAllElementsBST(TreeNode* root,vector<int> &ele){
    //     if(root==nullptr){
    //         return;
    //     }

    //     ele.push_back(root->val);
    //     getAllElementsBST(root->left,ele);
    //     getAllElementsBST(root->right,ele);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int> ele;
    //     getAllElementsBST(root,ele);

    //     // Sort
    //     sort(ele.begin(),ele.end());

    //     return ele[k-1];
    // }

    /*
    Time Complexity - O(nlogn)

    Space Complexity - O(h)
    */

    // Optimal Approach - inorder traversal returns elements in sorted order
     void OrderTraversal(TreeNode* root,vector<int>& ele){
        if(root==nullptr){
            return;
        }

        OrderTraversal(root->left,ele);
        ele.push_back(root->val);
        OrderTraversal(root->right,ele);
        
    }
    int kthSmallest(TreeNode* root, int k) {
       vector<int> ele;
       OrderTraversal(root,ele);

       return ele[k-1];
    }
};