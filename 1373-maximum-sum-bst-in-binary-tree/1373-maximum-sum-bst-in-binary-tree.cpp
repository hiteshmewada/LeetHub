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
    // {MIN_NUM, MAX_NUM, SUM}
    vector<int>find(TreeNode* root, int &ans){
        if(!root)
            return {INT_MAX, INT_MIN, 0};
        vector<int>left=find(root->left,ans),right=find(root->right,ans);
        // check if BST
        if(left.empty() or right.empty() or left[1]>=root->val or right[0]<=root->val) return {};
        // it is BST
        int cur_sum=(left[2]+right[2]+root->val);
        ans=max(ans,cur_sum);
        return {min(left[0],root->val),max(right[1],root->val),cur_sum};
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        find(root,ans);
        return max(0,ans);
    }
};