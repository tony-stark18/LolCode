/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if(root==null) return null;
        Queue<Node> q = new LinkedList<>();
        Node ln = new Node();
        q.add(root);
        while(!q.isEmpty()){
            Node curNode = q.remove();
            if(curNode.left!=null && curNode.right!=null){
                curNode.left.next = curNode.right;
                if(curNode.next!=null) curNode.right.next = curNode.next.left;
                q.add(curNode.left);
                q.add(curNode.right);
                ln = curNode;
            }
        }
        return root;
    }
}