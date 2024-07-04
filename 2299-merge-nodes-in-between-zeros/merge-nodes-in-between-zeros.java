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
        ListNode dummyHead = new ListNode(-1);
        ListNode t = dummyHead;
        ListNode temp = head.next;
        while(temp!=null){
            int sum = 0;
            while(temp!=null && temp.val!=0){
                sum+=temp.val;
                temp = temp.next;
            }
            // System.out.println(sum);
            t.next = new ListNode(sum);
            t=t.next;
            temp = temp.next;
        }
        return dummyHead.next;
    }
}