/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null) return null;
        var isCycle=false;
        var slow=head;
        var fast=head;
        while(fast!=null && fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
            if(slow==fast){
                isCycle=true;
                break;
            }
        }
        if(isCycle){
            var slow2=head;
            while(slow2!=slow){
                slow=slow.next;
                slow2=slow2.next;
            }
            return slow;
        }
        return null;
    }
}