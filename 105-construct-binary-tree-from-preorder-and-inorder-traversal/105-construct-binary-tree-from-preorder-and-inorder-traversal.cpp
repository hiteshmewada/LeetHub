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
    TreeNode* arrToTree(vector<int>& preorder, int l, int r){
        if(l>r) return NULL;
        int val=preorder[ind++];
        TreeNode *root=new TreeNode(val);
        root->left=arrToTree(preorder,l,mp[val]-1);
        root->right=arrToTree(preorder,mp[val]+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        ind=0;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return arrToTree(preorder,0,preorder.size()-1);
    }
};