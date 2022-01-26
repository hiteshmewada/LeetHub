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
    vector<int>ans;
    void fun(TreeNode* root){
        if(root==NULL) return ;
        ans.push_back(root->val);
         fun(root->left);
        fun(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // vector<int>ans;
        fun(root1);
        fun(root2);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};