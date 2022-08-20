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
    bool fun(TreeNode* root,TreeNode* &pre){
        if(!root) return true;
        if(!fun(root->left,pre)) return false;
        if(pre!=NULL and root->val<=pre->val) return false;
        pre=root;
        return fun(root->right,pre);
    }
    bool isValidBST(TreeNode* root) {
        // if(!root) return true;
        TreeNode *pre=NULL;
        return fun(root,pre);
    }
};