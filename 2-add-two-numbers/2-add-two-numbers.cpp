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
    ListNode* helper(ListNode* l1, ListNode* l2, int cy){
        if(!l1 and !l2 and !cy) return NULL;
        int sum=(l1?l1->val:0)+(l2?l2->val:0)+cy;
        ListNode *cur=new ListNode(sum%10);
        cur->next=helper(l1?l1->next:NULL,l2?l2->next:NULL,sum/10);
        return cur;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
           return helper(l1,l2,0);
    }
};