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
        if(!root) return ans;
        // st.push(root);
        
        while(st.size() or root){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                TreeNode *temp=st.top()->right;
                
                if(!temp){
                    temp=st.top();
                    ans.push_back(st.top()->val);
                    st.pop();
                    while(st.size() and st.top()->right==temp){
                        temp=st.top();
                        ans.push_back(st.top()->val);
                        st.pop();
                    }
                }
                else root=temp;
            }
        }
        return ans;
    }
};