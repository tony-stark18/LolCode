class Solution {
    public boolean findPath(TreeNode root, int target, StringBuilder path) {
        if (root == null) return false;
        if (root.val == target) return true;
        
        path.append('L');
        if (findPath(root.left, target, path)) return true;
        path.setLength(path.length() - 1); // backtrack
        
        path.append('R');
        if (findPath(root.right, target, path)) return true;
        path.setLength(path.length() - 1); // backtrack
        
        return false;
    }

    public String getDirections(TreeNode root, int s, int d) {
        StringBuilder pathToS = new StringBuilder();
        StringBuilder pathToD = new StringBuilder();

        findPath(root, s, pathToS);
        findPath(root, d, pathToD);

        // Find common path length
        int commonPathLength = 0;
        while (commonPathLength < pathToS.length() && commonPathLength < pathToD.length()
                && pathToS.charAt(commonPathLength) == pathToD.charAt(commonPathLength)) {
            commonPathLength++;
        }

        // Steps to move up from s to the common ancestor
        StringBuilder result = new StringBuilder();
        for (int i = commonPathLength; i < pathToS.length(); i++) {
            result.append('U');
        }

        // Steps to move down from the common ancestor to d
        result.append(pathToD.substring(commonPathLength));

        return result.toString();
    }
}
