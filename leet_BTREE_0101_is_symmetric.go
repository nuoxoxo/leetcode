/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return false
    }
    return helper(root.Left, root.Right)
}

func    helper(L *TreeNode, R *TreeNode) bool {
    if L == nil && R == nil {
        return true
    }
    if L == nil || R == nil {
        return false
    }
    return (L.Val == R.Val && helper(L.Left, R.Right) && helper(L.Right, R.Left))
}
