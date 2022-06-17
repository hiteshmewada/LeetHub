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
    ListNode* reverse(ListNode* cur){
        ListNode *pre=NULL,*nxt;
        while(cur){
            nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL and head->next==NULL) return true;
        ListNode *slow=head,*fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        ListNode *dummy=head;
        while(slow){
            if(dummy->val!=slow->val) return false;
            dummy=dummy->next;
            slow=slow->next;
        }
        return true;
    }
};