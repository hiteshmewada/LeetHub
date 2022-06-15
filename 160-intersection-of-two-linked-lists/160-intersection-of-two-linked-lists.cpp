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
    int getDiff(ListNode *headA, ListNode *headB){
        int l1=0,l2=0;
        while(headA or headB){
            if(headA){
                l1++;
                headA=headA->next;
            }
            if(headB) {
                l2++;
                headB=headB->next;
            }
        }
        return l1-l2;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len=getDiff(headA,headB);
        if(len<0){
            while(len<0) {
                len++;
                headB=headB->next;
            }
        }
        else if(len>0){
            while(len>0) {
                len--;
                headA=headA->next;
            }
        }
        while(headB){
            if(headA==headB) return headB;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};