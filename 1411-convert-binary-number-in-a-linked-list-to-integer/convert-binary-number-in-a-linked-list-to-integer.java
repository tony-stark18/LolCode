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
        ListNode temp=head,temp1=head;
        int ans=0,i=0,cnt=0;
        while(temp!=null){
            // ans+=temp.val * Math.pow(2, i++);
            cnt++;
            temp=temp.next;
        }
         while(temp1!=null){
            ans+=temp1.val * Math.pow(2, --cnt);
            temp1=temp1.next;
        }


        return ans;
        
    }
}