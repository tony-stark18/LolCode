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
    public int getLength(ListNode head){
        ListNode temp = head;
        int cnt = 0;
        while(temp!=null){
            cnt++;
            temp=temp.next;
        }
        return cnt;
    }
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] ls = new ListNode[k];
        int len = getLength(head);
        if(len==0) return ls;
        if(len<k){
            for(int i=0;i<k;i++){
                ListNode temp = head;
                if(head.next!=null) head = head.next;
                temp.next = null;
                if(i<len){
                    ls[i] = temp;
                }
                else{
                    ls[i] = null;
                }
            }
        }
        else{
            int extraNode = len%k;
            int n = len/k;
            ListNode nextHead = head;
            for(int i=0;i<k;i++){
                head = nextHead;
                ListNode temp = nextHead;
                int extra = extraNode>0?1:0;
                extraNode--;
                for(int j=0;j<n+extra-1;j++){
                    temp = temp.next;
                }
                if(temp!=null) nextHead = temp.next;
                temp.next = null;
                ls[i]=head;
            }
        }
        return ls;
    }
}