/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL) return NULL;
        ListNode *dummy=NULL;
        while(head!=NULL){
           ListNode *nxt=head->next;
            head->next=dummy;
            dummy=head;
            head=nxt;
        }
        // head=pre;
        return dummy;
    }
};