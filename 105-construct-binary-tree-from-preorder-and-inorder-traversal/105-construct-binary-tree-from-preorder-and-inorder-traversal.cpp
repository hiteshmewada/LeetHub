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
    int preorderIndex;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<preorder.size();i++) 
            mp[inorder[i]]=i;
       TreeNode* root= arrayToTree(preorder,0,preorder.size()-1,
                           inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* arrayToTree(vector<int>& preorder, int preStart, int preEnd,
                          vector<int>&inorder, int inStart, int inEnd,
                          map<int,int>&mp){
        if(preStart>preEnd or inStart>inEnd) return NULL;
        TreeNode *root=new TreeNode(preorder[preStart]);
        int inRoot=mp[root->val];
        int numsLeft=inRoot-inStart;
        root->left=arrayToTree(preorder,preStart+1,preStart+numsLeft, 
                               inorder, inStart, inRoot-1, mp);
        root->right=arrayToTree(preorder,preStart+1+numsLeft,preEnd, 
                               inorder, inRoot+1, inEnd, mp);
        return root;
    }
};