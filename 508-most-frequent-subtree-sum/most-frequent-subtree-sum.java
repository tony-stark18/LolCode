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
    public int sumTree(TreeNode root, HashMap<Integer,Integer> hs){
        if(root==null) return 0;
        int ls = sumTree(root.left,hs);
        int rs = sumTree(root.right,hs);
        int sum = ls+rs+root.val;
        hs.put(sum,hs.getOrDefault(sum,0)+1);
        return sum;
    }
    public int[] findFrequentTreeSum(TreeNode root) {
        HashMap<Integer,Integer> hs = new HashMap<>();
        sumTree(root,hs);

        int maxFrequency = 0;
        for (int frequency : hs.values()) {
            maxFrequency = Math.max(maxFrequency, frequency);
        }
        List<Integer> ls = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : hs.entrySet()) {
            if (entry.getValue() == maxFrequency) {
                ls.add(entry.getKey());
            }
        }
        int arr[] = new int[ls.size()];
        for(int i=0;i<ls.size();i++){
            arr[i]=ls.get(i);
        }
        return arr;
    }
}