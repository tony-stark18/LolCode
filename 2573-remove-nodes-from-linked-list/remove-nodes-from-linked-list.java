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
    public ListNode removeNodes(ListNode head) {
        if(head==null) return null;
        ListNode temp = head;
        Stack<ListNode> st = new Stack<>();
        while(temp!=null){
            st.push(temp);
            temp = temp.next;
        }
        ListNode node = st.pop();
        int maxVal = node.val;
        boolean toRemove = false;
        while(!st.isEmpty()){
            temp = st.pop();
            if(toRemove){
                temp.next= temp.next.next;
            }
            if(temp.val<maxVal){
                toRemove = true;
            }
            else{
                maxVal = temp.val;
                toRemove = false;
            }
        }
        if(toRemove) head=head.next;
        return head;
    }
}