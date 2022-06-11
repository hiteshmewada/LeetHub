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
        ListNode *dummy=new ListNode();// dummy node is used for edge case when head->next->next gives wrong values where n==len of linked list.
        dummy->next=head;
        ListNode *slow=dummy,*fast=dummy;
        for(int i=0;i<n;i++) fast=fast->next;
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return dummy->next;
    }
};