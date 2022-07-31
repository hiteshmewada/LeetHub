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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(q.size()){
            auto x=q.front();
            q.pop();
            root=x.first;
            int a=x.second.first,b=x.second.second;
            mp[a][b].insert(root->val);
            if(root->left) q.push({root->left,{a-1,b+1}});
            if(root->right) q.push({root->right,{a+1,b+1}});
        }
        for(auto x:mp){
            vector<int>v;
            for(auto y:x.second){
                v.insert(v.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};