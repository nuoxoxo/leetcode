/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func replaceValueInTree(root *TreeNode) *TreeNode {

    levelsums := []int{}

    var dfs_levelsums func(*TreeNode, int)
    dfs_levelsums = func(node *TreeNode, depth int) {
        if node == nil { return }
        if depth > len(levelsums) - 1 {
            levelsums = append(levelsums, 0)
        }
        levelsums[depth] += node.Val
        dfs_levelsums(node.Left, depth + 1)
        dfs_levelsums(node.Right, depth + 1)
    }

    dfs_levelsums(root, 0)
    // fmt.Println(levelsums)

    var dfs_dostuff func(*TreeNode, int, int)
    dfs_dostuff = func(node *TreeNode, depth int, cousinsum int) {
        if node == nil { return }
        node.Val = levelsums[depth] - cousinsum
        cousinsum = 0
        if node.Left != nil { cousinsum += node.Left.Val }
        if node.Right != nil { cousinsum += node.Right.Val }
        dfs_dostuff(node.Left, depth + 1, cousinsum)
        dfs_dostuff(node.Right, depth + 1, cousinsum)
    }

    dfs_dostuff(root, 0, root.Val)

    return root
}
