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
        if(root==nullptr){
            return {};
        }
        vector<vector<int>> level;
        queue<TreeNode*> Que;
        vector<int> temp;

        Que.push(root);
        Que.push(nullptr);

        while(!Que.empty()){
            TreeNode* curr = Que.front();
            Que.pop();
            if(curr==nullptr){
                level.push_back(temp);
                temp.clear();
                if(Que.empty()){
                    break;
                }
                else{
                    Que.push(nullptr);
                    continue;
                }
            }

            temp.push_back(curr->val);
            if(curr->left){
                Que.push(curr->left);
            }
            if(curr->right){
                Que.push(curr->right);
            }

            
        }
        return level;
    }

    /*
    Time Comlexity - O(n)

    Space Complexity - O(n)
    */
};