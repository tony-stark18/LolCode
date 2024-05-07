/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode doubleIt(ListNode head) {
        Stack<ListNode> st = new Stack<>();
        ListNode temp = head;
        while (temp != null) {
            st.push(temp);
            temp = temp.next;
        }
        int carry = 0;
        while (!st.isEmpty()) {
            ListNode node = st.pop();
            int x = node.val*2+carry;
            if (x > 9) {
                node.val = x-10;
                carry = 1;
            } else {
                node.val = x;
                carry = 0;
            }
        }
        if(carry==1){
            ListNode newHead = new ListNode(1);
            newHead.next = head;
            return newHead;
        }
        return head;
    }
}