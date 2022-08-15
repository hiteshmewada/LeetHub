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
    int ind;
    map<int,int>mp;
    TreeNode* toTree(vector<int>& postorder,int l, int r){
        if(l>r) return NULL;
        int val=postorder[ind--];
        TreeNode *root=new TreeNode(val);
        root->right=toTree(postorder,mp[val]+1,r);
        root->left=toTree(postorder,l,mp[val]-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        ind=postorder.size()-1;
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        return toTree(postorder,0,n-1);
    }
};