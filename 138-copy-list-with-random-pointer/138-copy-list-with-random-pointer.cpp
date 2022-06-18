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
        Node *iter=head,*front=head;
        
        // First round make copy of each node and link them together side-by-side in a single list
        while(iter){
            front=iter->next;
            Node *copy=new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        
        // Second round: assign random pointers for the copy nodes 
        
        iter=head;
        while(iter){
            if(iter->random){
                iter->next->random=iter->random->next;
            }
            iter=iter->next->next;
        }
        
        // Third round: restore the original list and extract the copy list
        
        iter=head;
        Node *pseudoHead=new Node(0);
        Node *copy=pseudoHead;
        
        while(iter){
            front=iter->next->next;
            
            // extract copy
            copy->next=iter->next;
            
            // restore original list
            iter->next=front;
            
            copy=copy->next;
            iter=front;
        }
        return pseudoHead->next;
    }
};