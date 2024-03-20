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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode temp = list1;
        int i=1;
        for(;i<a;i++){
            temp=temp.next;
        }
        ListNode t1 = temp;
        System.out.println(t1.val);
        for(;i<=b;i++){
            temp = temp.next;
        }
        ListNode t2 = temp;
        ListNode tail = list2;
        while(tail.next!=null){
            tail=tail.next;
        }
        t1.next = list2;
        tail.next = t2.next;
        System.out.println(t2.val);
        return list1;
    }
}