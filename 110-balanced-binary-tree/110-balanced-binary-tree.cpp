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
    bool fun(TreeNode* root,int l,int r){
        if(!root) return  true;
        fun(root->left,l+1,r);
        fun(root->right,l,r);
        if(abs(l-r)<=1) return true;
        return false;
    }
    int rec(TreeNode* root){
        if(!root) return 0;
        return 1+max(rec(root->left),rec(root->right));
    }
    int recr(TreeNode* root){
        if(!root) return 0;
        return 1+rec(root->right);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        // int l=fun(root->left,0);
        // int r=fun(root->right,0);
        // if(abs(l-r)<=1) return true;
        // return false;
        int l=rec(root->left);
        int r=rec(root->right);
        if(abs(l-r)<=1 and isBalanced(root->left) and isBalanced(root->right)) return true;
        return false;
    }
};