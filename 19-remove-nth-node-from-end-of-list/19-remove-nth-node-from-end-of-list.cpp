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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node=head;
        int len=0;
        while(node){
            len++;
            node=node->next;
        }
        node=head;
        len-=n;
        if(len==0){
            
            if(!head) return head;
            // ListNode  *cur=head->next;
            // if(head and head->next  )
            // cur->next=head->next;
            // else return NULL;
            // delete head;
            head=head->next;
            return head;
        }
        for(int i=0;i<len-1;i++){
            
            node=node->next;
            
        }
        node->next=node->next->next;
        return head;
    }
};