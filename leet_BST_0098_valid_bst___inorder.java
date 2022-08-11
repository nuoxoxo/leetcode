
class Solution {
    public boolean isValidBST(TreeNode root)
    {
        ArrayList<Integer>  n = new ArrayList<>();
        int                 i = 0;

        inorder(root, n);
        while (++i < n.size())
            if (n.get(i - 1) >= n.get(i))
                return false;
        return true;
    }

    public void inorder(TreeNode node, ArrayList<Integer> nums)
    {
        if (node == null)
            return ;
        inorder(node.left, nums);
        nums.add(node.val);
        inorder(node.right, nums);
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
