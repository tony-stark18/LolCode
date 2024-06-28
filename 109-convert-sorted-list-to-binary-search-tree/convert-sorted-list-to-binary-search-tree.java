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
    public TreeNode construct(List<Integer> ls,int left,int right){
        if(left>right) return null;
        if(left==right) return new TreeNode(ls.get(left));
        int mid =(left+right)/2;
        TreeNode root = new TreeNode(ls.get(mid));
        root.left = construct(ls,left,mid-1);
        root.right = construct(ls,mid+1,right);
        return root;
    }
    public TreeNode sortedListToBST(ListNode head) {
        List<Integer> ls = new ArrayList<>();
        while(head!=null){
            ls.add(head.val);
            head = head.next;
        }
        int left = 0;
        int right = ls.size()-1;
        return construct(ls,left,right);
    }
}