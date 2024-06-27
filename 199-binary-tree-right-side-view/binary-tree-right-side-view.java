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
    public void soln(TreeNode root,List<Integer> ans,int rightMaxDepth[],int curDepth){
        if(root==null) return ;
        if(curDepth>rightMaxDepth[0]){
            ans.add(root.val);
            rightMaxDepth[0]=curDepth;
        }
        soln(root.right,ans,rightMaxDepth,curDepth+1);
        soln(root.left,ans,rightMaxDepth,curDepth+1);
    }
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        int rightMaxDepth[] = {-1};
        soln(root,ans,rightMaxDepth,0);
        return ans;
    }
}