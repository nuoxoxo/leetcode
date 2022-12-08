/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
    a1 := []int {}
    a2 := []int {}
    dfs_on_single_node(root1, & a1)
    dfs_on_single_node(root2, & a2)
    fmt.Println(a1)
    fmt.Println(a2)
    if len(a1) != len(a2) {
        return false
    }
    for i := range a1 {
        if a1[i] != a2[i] {
            return false
        }
    }
    return true
}

//  helper:

func dfs_on_single_node(node *TreeNode, a *[]int) {
    if node == nil {
        return
    }
    if node.Left == nil && node.Right == nil {
        *a = append(*a, node.Val)
        return
    }
    dfs_on_single_node(node.Left, a)
    dfs_on_single_node(node.Right, a)
}
