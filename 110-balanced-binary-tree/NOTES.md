/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/
class Solution {
public:
int rec(TreeNode* root){
if(!root) return 0;
return 1+max(rec(root->left),rec(root->right));
}
bool isBalanced(TreeNode* root) {
if(!root) return true;
int l=rec(root->left);
int r=rec(root->right);
if(abs(l-r)<=1 and isBalanced(root->left) and isBalanced(root->right)) return true;
return false;
}
};