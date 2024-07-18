/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }1
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    //post-order
    public List<Integer> soln(TreeNode root,int d,int ans[]){
        if(root==null) return new ArrayList<>();
        if(root.left==null && root.right==null){
            List<Integer> res = new ArrayList<>();
            res.add(1);
            return res;
        }
        List<Integer> ls = soln(root.left,d,ans);
        List<Integer> rs = soln(root.right,d,ans);
        for(int i=0;i<ls.size();i++){
            for(int j=0;j<rs.size();j++){
                if(ls.get(i)+rs.get(j)<=d)
                    ans[0]+=1;
            }
        }
        List<Integer> res = new ArrayList<>();
        for(int i=0;i<ls.size();i++){
            if(ls.get(i)+1<d){
                res.add(ls.get(i)+1);
            }
        }
        for(int i=0;i<rs.size();i++){
            if(rs.get(i)+1<d){
                res.add(rs.get(i)+1);
            }
        }
        return res; 
    }
    public int countPairs(TreeNode root, int distance) {
        int ans[] = new int[1];
        soln(root,distance,ans);
        return ans[0];
    }
}