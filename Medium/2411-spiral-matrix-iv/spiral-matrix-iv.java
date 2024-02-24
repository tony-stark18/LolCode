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
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int matrix[][] = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = -1;
            }
        }

        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        
        while (head!=null) {
            for (int j = left; j <= right && head!=null; j++) {
                matrix[top][j] = head.val;
                head = head.next;
            }
            top++;
            
            for (int i = top; i <= bottom && head!=null; i++) {
                matrix[i][right]=head.val;
                head = head.next;
            }
            right--;
            
            for (int j = right; j >= left && head!=null; j--) {
                matrix[bottom][j] = head.val;
                head = head.next;
            }
            bottom--;
            
            for (int i = bottom; i >= top && head!=null; i--) {
                matrix[i][left] = head.val;
                head = head.next;
            }
            left++;
        }
        return matrix;
    }
}