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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        if(!root){
            return nodes;
        }
        vector<int> level;
        queue<TreeNode*> que;
        que.push(root);
        que.push(nullptr);
        while(!que.empty()){
            TreeNode* curr = que.front();
            que.pop();
            level.push_back(curr->val);

            if(curr->left){
                que.push(curr->left);
            }
            if(curr->right){
                que.push(curr->right);
            }

            if(que.front()==nullptr){
                nodes.push_back(level);
                que.pop();
                if(que.empty()){
                    break;
                }
                que.push(nullptr);
                level = {};
            }
        }

        return nodes;
    }
};