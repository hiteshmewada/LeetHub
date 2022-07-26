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
    
    vector<int> inorderTraversal(TreeNode* root) {
       stack<TreeNode*>st;
        while(true){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                if(st.empty()) break;
                ans.push_back(st.top()->val);
                root=st.top();
                st.pop();
                root=root->right;
            }
        }
        return ans;
    }
};