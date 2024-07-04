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
        ListNode dummyHead = new ListNode(0); // Create a dummy node to hold the new list
        ListNode t = dummyHead; // Pointer to build the new list
        ListNode temp = head.next; // Skip the initial 0

        int sum = 0; // Initialize sum to accumulate values

        while (temp != null) {
            if (temp.val == 0) {
                // When we encounter a 0, we create a new node with the sum of the previous segment
                t.next = new ListNode(sum);
                t = t.next; // Move the pointer to the new node
                sum = 0; // Reset the sum for the next segment
            } else {
                // Accumulate the sum of the current segment
                sum += temp.val;
            }
            temp = temp.next; // Move to the next node
        }
        return dummyHead.next; // Return the next node of the dummy head, which is the start of the new list
    }
}
