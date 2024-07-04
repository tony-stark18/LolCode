/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode dummyHead = head;
        ListNode t = dummyHead;
        ListNode temp = head.next;
        dummyHead.next = null;

        while(temp!=null){
            int sum = 0;
            while(temp!=null){
                if(temp.next.val==0){
                    temp.next.val = sum+temp.val;
                    t.next = temp.next;
                    temp.next = null;
                    t=t.next;
                    temp = t.next;
                    t.next=null;
                    break;
                }
                sum+=temp.val;
                temp = temp.next;
            }
        }
        return dummyHead.next;
    }
}