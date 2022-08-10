/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */

object Solution {
    def sortedArrayToBST(nums: Array[Int]): TreeNode = {
        if (nums == null)       return null
        if (nums.length == 0)   return null
        make_tree(nums, 0, nums.length - 1)
    }

    def make_tree(n: Array[Int], L: Int, R: Int) : TreeNode = {
        if (L > R)  null
        else {
            val mid = ((R - L) >> 1) + L
            // val mid = (R - L) / 2 + L
            val node = new TreeNode(n(mid))
            node.left = make_tree(n, L, mid - 1)
            node.right = make_tree(n, mid + 1, R)
            node
        }
    }
}
