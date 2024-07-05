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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        ListNode next;
        int first = -1;
        int lastCritical = -1;
        int last = -1;
        int ind = 0;
        int minD = Integer.MAX_VALUE;
        while (curr != null) {
            next = curr.next;
            ind++;
            if (prev != null && next != null
                    && ((prev.val > curr.val && curr.val < next.val) || (prev.val < curr.val && curr.val > next.val))) {
                if (first == -1) {
                    first = ind;
                }
                else{
                    minD = Math.min(minD,ind-lastCritical);
                }
                lastCritical = ind;
            }
            prev = curr;
            curr = next;
        }
        int arr[] = { -1, -1 };
        if (first == -1 || first==lastCritical)
            return arr;
        arr[0] = minD;
        arr[1] = lastCritical - first;
        return arr;
    }
}