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
    public int pairSum(ListNode head) {
        if(head == null)
            return 0;
        if(head.next == null)
            return head.val;
    
        ListNode temp = head;
        int n=0;
        while(temp != null){
            temp = temp.next;
            n++;
        }
        temp = head;
        int k = n/2;
        for(int i=0;i<k-1;i++){
            temp = temp.next;
        }
        ListNode curr = temp.next;
        temp.next = null;
        ListNode prev,after;
        prev = null;
        while(curr != null){
            after = curr.next;
            curr.next = prev;
            prev = curr;
            curr = after;
        }
        ListNode newHead = prev;
        //Iterate through both the Lists
        //ListNode temp1, temp2;
        temp = head;
        curr = newHead;
        int max = Integer.MIN_VALUE,sum = 0;
        while(temp!=null){
            sum = temp.val + curr.val;
            if(sum > max)
                max = sum;
            temp = temp.next;
            curr = curr.next;    
        }
    return max;
    }
}