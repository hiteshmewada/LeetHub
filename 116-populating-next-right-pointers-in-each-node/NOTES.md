BFS
​
/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;
Node* next;
​
Node() : val(0), left(NULL), right(NULL), next(NULL) {}
​
Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
​
Node(int _val, Node* _left, Node* _right, Node* _next)
: val(_val), left(_left), right(_right), next(_next) {}
};
*/
​
class Solution {
public:
Node* connect(Node* root) {
if(!root) return root;
queue<Node*>q;
q.push(root);
Node *ans=root;
while(q.size()){
Node *temp=NULL;
int n=q.size();
while(n--){
root=q.front();
q.pop();
root->next=temp;
temp=root;
if(root->right) q.push(root->right);
if(root->left) q.push(root->left);
}
}
return ans;
}
};