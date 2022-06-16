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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;
        ListNode *node=head;
        while(node) {
            len++;
            node=node->next;
        }
        ListNode *dummy=new ListNode();
        dummy->next=head;
        ListNode *pre=dummy,*cur,*nxt;
        while(len>=k){
            cur=pre->next;
            nxt=cur->next;
            for(int i=1;i<k;i++){
                cur->next=nxt->next;
                nxt->next=pre->next;
                pre->next=nxt;
                nxt=cur->next;
            }
            pre=cur;
            len-=k;
        }
        return dummy->next;
    }
};