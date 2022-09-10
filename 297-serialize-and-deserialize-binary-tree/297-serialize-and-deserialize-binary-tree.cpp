/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            root=q.front();
            q.pop();
            if(root==NULL) s+="=,";
            else{
                s+=to_string(root->val);
                s+=",";
            }
            if(root){
                q.push(root->left);
                q.push(root->right);
            }
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *node=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(node);
        while(q.size()){
            TreeNode *root=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="=") root->left=NULL;
            else{
                TreeNode *temp=new TreeNode(stoi(str));
                root->left=temp;
                q.push(temp);
            }
            getline(s,str,',');
            if(str=="=") root->right=NULL;
            else{
                TreeNode *temp=new TreeNode(stoi(str));
                root->right=temp;
                q.push(temp);
            }
        }
        return node;
    }
};




























// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));