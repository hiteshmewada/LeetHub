/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *cur=head,*nxt;
        while(cur){
            nxt=cur->next;
            Node *naya=new Node(cur->val);
            naya->next=nxt;
            cur->next=naya;
            cur=nxt;
        }
        cur=head;
        while(cur){
            if(cur->random){
                cur->next->random=cur->random->next;
            }
            cur=cur->next->next;
        }
        Node *temp=new Node(0);
        Node *copy=temp;
        cur=head;
        while(cur){
            nxt=cur->next->next;
            copy->next=cur->next;
            copy=copy->next;
            cur->next=nxt;
            cur=nxt;
        }
        return temp->next;
    }
};