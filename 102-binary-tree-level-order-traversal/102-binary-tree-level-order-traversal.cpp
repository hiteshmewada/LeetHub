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
        vector<vector<int>>ans;
        if(!root) return {};
        // ans.push_back({root->val});
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
             queue<TreeNode*>temp;
            temp=q;
            vector<int>vec;
            while(!temp.empty()){
                TreeNode *cur=temp.front();
                temp.pop();
                q.pop();
                vec.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};