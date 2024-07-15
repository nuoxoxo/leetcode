/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func createBinaryTree(descriptions [][]int) *TreeNode {

    nodes := make(map[int] *TreeNode)
    ischild := make(map[int]bool)
    for _, t := range descriptions {
        parent := t[0]
        child := t[1]
        isleft := t[2]
        if _, isset := nodes[parent]; ! isset {
            nodes[parent] = & TreeNode{ Val : parent }
        }
        if _, isset := nodes[child]; ! isset {
            nodes[child] = & TreeNode{ Val : child }
        }
        if isleft == 1 {
            nodes[parent].Left = nodes[child]
        } else {
            nodes[parent].Right = nodes[child]
        }
        ischild[child] = true
    }
    var res * TreeNode
    for node, realnode := range nodes {
        if ! ischild[node] {
            res = realnode
            break
        }
    }
    return res

}
