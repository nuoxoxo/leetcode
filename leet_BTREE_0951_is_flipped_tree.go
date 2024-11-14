/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func flipEquiv(root1 *TreeNode, root2 *TreeNode) bool {
    var check func(*TreeNode, *TreeNode) bool
    check = func(L *TreeNode, R *TreeNode) bool {
        if L == nil && R == nil {
            return true
        }
        if L == nil && R != nil || L != nil && R == nil || L.Val != R.Val {
            return false
        }
        return check(L.Left, R.Left) && check(L.Right, R.Right) ||
            check(L.Left, R.Right) && check(L.Right, R.Left)
    }
    return check(root1, root2)
}
