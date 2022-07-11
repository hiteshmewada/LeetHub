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
    vector<vector<int>>ans;
    void fun(TreeNode* root,int i){
        if(root==NULL) return ;
        ans[i].push_back(root->val);
        fun(root->left,i+1);
        fun(root->right,i+1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        ans.resize(100,{});
        fun(root,0);
        vector<int>res;
        for(auto x:ans){
            vector<int>v=x;
            if(v.size())
            res.push_back(v[v.size()-1]);
        }
        return res;
    }
};