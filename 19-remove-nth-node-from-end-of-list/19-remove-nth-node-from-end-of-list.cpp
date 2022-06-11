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
        if(head==NULL) return head;
        int sz=0;
        ListNode *cur=head;
        while(cur){
            sz++;
            cur=cur->next;
        }
        cur=head;
        if(sz==n){
            ListNode *node=head;
            head=head->next;
            delete node;
            return head;
        }
        int cnt=1;
        sz-=n;
        while(cnt!=sz){
            cur=cur->next;
            cnt++;
        }
        ListNode *node=cur->next;
           cur->next=node->next;
        delete node;
        return head;
            
    }
};