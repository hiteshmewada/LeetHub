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
    
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        stack<TreeNode*>st2;
        if(!root) return  ans;
        st.push(root);
        while(st.size()){
            
            root=st.top();
            st.pop();
            st2.push(root);
            if(root->left!=NULL) st.push(root->left);
            if(root->right!=NULL) st.push(root->right);
        }
        while(st2.size()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};