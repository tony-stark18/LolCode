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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        ListNode previous = null;
        ListNode current = head;
        ListNode next;
        int firstCriticalPointIndex = -1;
        int lastCriticalPointIndex = -1;
        int currentIndex = 0;
        int minimumDistance = Integer.MAX_VALUE;

        while (current != null) {
            next = current.next;
            currentIndex++;

            if (previous != null && next != null &&
                ((previous.val > current.val && current.val < next.val) ||
                 (previous.val < current.val && current.val > next.val))) {
                 
                if (firstCriticalPointIndex == -1) {
                    firstCriticalPointIndex = currentIndex;
                } else {
                    minimumDistance = Math.min(minimumDistance, currentIndex - lastCriticalPointIndex);
                }
                lastCriticalPointIndex = currentIndex;
            }

            previous = current;
            current = next;
        }

        int result[] = { -1, -1 };
        if (firstCriticalPointIndex == -1 || firstCriticalPointIndex == lastCriticalPointIndex) {
            return result;
        }

        result[0] = minimumDistance;
        result[1] = lastCriticalPointIndex - firstCriticalPointIndex;
        return result;
    }
}
