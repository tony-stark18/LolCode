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
    public int getDecimalValue(ListNode head) {
        int len = -1;
        ListNode temp = head;
        while(temp!=null){
            len++;
            temp= temp.next;
        }
        System.out.println(len);
        int res=0;
        while(head!=null){
            res+=head.val*Math.pow(2,len);
            len--;
            head=head.next;
        }
        return res;
    }
}