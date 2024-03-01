import java.util.*;

public class Solution {
    public int getMin(TreeNode root, int[] noOfNodes) {
        if (root == null) {
            return Integer.MAX_VALUE;
        }
        noOfNodes[0] += 1;
        int lr = getMin(root.left, noOfNodes);
        int rr = getMin(root.right, noOfNodes);
        return Math.min(root.val, Math.min(lr, rr));
    }

    public void buildGraph(TreeNode root, List<List<Integer>> adj, int min) {
        if (root == null) return;

        if (root.left != null) {
            adj.get(root.val - min).add(root.left.val - min);
            adj.get(root.left.val - min).add(root.val - min);
            buildGraph(root.left, adj, min);
        }

        if (root.right != null) {
            adj.get(root.val - min).add(root.right.val - min);
            adj.get(root.right.val - min).add(root.val - min);
            buildGraph(root.right, adj, min);
        }
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        List<Integer> ls = new ArrayList<>();
        int noOfNodes[] = new int[1];
        int min = getMin(root, noOfNodes);
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < noOfNodes[0]; i++) {
            adj.add(new ArrayList<>()); // Initialize inner list
        }
        buildGraph(root, adj, min);

        // Print the adjacency list for debugging
        // for (int i = 0; i < noOfNodes[0]; i++) {
        //     System.out.print(i + " -> ");
        //     for (int j = 0; j < adj.get(i).size(); j++) {
        //         System.out.print(adj.get(i).get(j) + " ");
        //     }
        //     System.out.println();
        // }

        List<Integer> vis = new ArrayList<>();
        for (int i = 0; i < noOfNodes[0]; i++) {
            vis.add(0);
        }
        Queue<Integer> q = new LinkedList<>();
        q.add(target.val - min);
        vis.set(target.val - min, 1);
        int lv = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int node = q.remove();
                if (lv == k) {
                    ls.add(node + min);  // Add the actual node value, not the index
                }
                for (int neighbor : adj.get(node)) {
                    if (vis.get(neighbor) == 0) {
                        q.add(neighbor);
                        vis.set(neighbor, 1);
                    }
                }
            }
            lv++;
        }

        return ls;
    }
}