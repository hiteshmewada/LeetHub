/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head or !(head->next)) return NULL;
        ListNode *slow=head,*fast=head,*entry=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                fast=head;
                while(slow!=fast) {
                    slow=slow->next;fast=fast->next;
                }
                return slow;
            }
            
        }
         return NULL;
        // fast=head;
        
    }
};