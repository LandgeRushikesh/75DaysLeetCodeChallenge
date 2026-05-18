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
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> Que;

        Que.push(root);
        Que.push(nullptr);

        while(!Que.empty()){
            TreeNode* curr = Que.front();
            Que.pop();
            if(curr==nullptr){
                break;
            }
            if(curr->left){
                Que.push(curr->left);
            }
            if(curr->right){
                Que.push(curr->right);
            }
            if(Que.front()==nullptr){
                ans.push_back(curr->val);
                Que.pop();
                Que.push(nullptr);
            }
        }
        return ans;
    }
};