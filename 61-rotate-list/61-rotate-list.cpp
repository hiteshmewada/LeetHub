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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next) return head;
        int len=0;
        ListNode *temp=head;
        while(temp->next){
            len++;
            temp=temp->next;
        }
        temp->next=head;
        len++;
        k=k%len;
        len-=k;
        if(len==0) return head;
        temp=head;
        len--;
        while(len--){
            temp=temp->next;
        }
        ListNode *ans;
        ans=temp->next;
        temp->next=NULL;
        // while(ans->next) ans=ans->next;
        // ans->next=temp;
        return ans;
    }
};