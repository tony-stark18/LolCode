/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public TreeNode createBinaryTree(int[][] d) {
        HashMap<Integer, TreeNode> hs = new HashMap<>();
        HashSet<Integer> child = new HashSet<>();
        TreeNode root = null;
        for (int i = 0; i < d.length; i++) {
            if (hs.containsKey(d[i][0])) {
                TreeNode node = hs.get(d[i][0]);
                if (d[i][2] == 1) {
                    if (hs.containsKey(d[i][1])) {
                        node.left = hs.get(d[i][1]);
                    } else {
                        node.left = new TreeNode(d[i][1]);
                        hs.put(d[i][1],node.left);
                    }
                    child.add(node.left.val);
                } else {
                    if (hs.containsKey(d[i][1])) {
                        node.right = hs.get(d[i][1]);
                    } else {
                        node.right = new TreeNode(d[i][1]);
                        hs.put(d[i][1],node.right);
                    }
                    child.add(node.right.val);
                }
            } else {
                TreeNode node = new TreeNode(d[i][0]);
                if (d[i][2] == 1) {
                    if (hs.containsKey(d[i][1])) {
                        node.left = hs.get(d[i][1]);
                    } else {
                        node.left = new TreeNode(d[i][1]);
                        hs.put(d[i][1],node.left);
                    }
                    child.add(node.left.val);
                } else {
                    if (hs.containsKey(d[i][1])) {
                        node.right = hs.get(d[i][1]);
                    } else {
                        node.right = new TreeNode(d[i][1]);
                        hs.put(d[i][1],node.right);
                    }
                    child.add(node.right.val);
                }
                hs.put(node.val,node);
            }
        }
        for(int key:hs.keySet()){
            if(!child.contains(key)){
                root = hs.get(key);
                break;
            }
        }
        // if(root==null) return hs.get(d[0][0]);
        return root;
    }
}