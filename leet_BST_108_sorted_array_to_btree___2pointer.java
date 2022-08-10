
class Solution {
    public TreeNode sortedArrayToBST(int[] nums)
    {
        return make_tree(nums, 0, nums.length - 1);
    }

    public TreeNode make_tree(int[] n, int L, int R)
    {
        TreeNode    node;
        int         mid;

        if (L > R)
            return null;
        mid = ((R - L) >> 1) + L;
        node = new TreeNode(n[mid]);
        node.left = make_tree(n, L, mid - 1);
        node.right = make_tree(n, mid + 1, R);
        return node;
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
