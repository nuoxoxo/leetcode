/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
        var here int = root.Val
        var pv int = p.Val
        var qv int = q.Val
        if here > pv && here > qv {
            return lowestCommonAncestor(root.Left, p, q)
        }
        if here < pv && here < qv {
            return lowestCommonAncestor(root.Right, p, q)
        }
        return root
}
