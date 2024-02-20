class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode leftSubList = dummy;
        ListNode curr = head;

        for(int i=1;i<left;i++){
            leftSubList = curr;
            curr = curr.next;
        }

        ListNode rt = curr;
        ListNode prev = null;
        ListNode next;
        for(int i=left;i<=right;i++){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        leftSubList.next = prev;
        rt.next = curr;

        return dummy.next;
    }
}
