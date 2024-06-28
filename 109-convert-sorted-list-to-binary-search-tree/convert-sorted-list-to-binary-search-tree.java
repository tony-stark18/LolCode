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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public ListNode getMid(ListNode head){
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast!=null && fast.next!=null && fast.next.next!=null){
            slow=slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
    public TreeNode construct(ListNode head){
        if(head==null) return null;
        if(head.next==null) return new TreeNode(head.val);
        ListNode mid = getMid(head);
        TreeNode root = new TreeNode(mid.next.val);
        System.out.println(mid.val);
        ListNode rightHead = mid.next.next;
        mid.next = null;
        root.left = construct(head);
        root.right = construct(rightHead);
        return root;
    }
    public TreeNode sortedListToBST(ListNode head) {
        return construct(head);
    }
}