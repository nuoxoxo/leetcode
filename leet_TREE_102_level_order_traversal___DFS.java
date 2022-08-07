
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root)
    {
        List<List<Integer>> res;

        if (root == null)
            return new LinkedList<>();
        res = new LinkedList<>();
        dfs(res, root, 0);
        return res;
    }

    public void dfs(List<List<Integer>> res, TreeNode node, int level)
    {
        if (node == null)
            return ;
        if (res.size() == level)
            res.add(new LinkedList<>());
        res.get(level).add(node.val);
        dfs(res, node.left, level + 1);
        dfs(res, node.right, level + 1);
    }
}

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
