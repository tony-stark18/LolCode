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
    public void SumN(TreeNode root,int num,List<Integer> ls){
        if(root==null){
            return;
        }
        if(root.left==null && root.right==null){
            ls.add(num*10+root.val);
            return;
        }
        num = num*10+root.val;
        SumN(root.left,num,ls);
        SumN(root.right,num,ls);
    }
    public int sumNumbers(TreeNode root) {
        if(root==null) return 0;
        List<Integer> ls = new ArrayList<>();
        SumN(root,0,ls);
        int res=0;
        for(int i:ls){
            res+=i;
            System.out.println(i);
        }
        return res;
    }
}