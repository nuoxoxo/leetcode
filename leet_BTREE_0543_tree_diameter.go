/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func diameterOfBinaryTree(root *TreeNode) int {
    Solutions := []func(*TreeNode)int{
        // Solution_Two_func,
        Solution_One_func,
    }
    return Solutions[0](root);
}

func Solution_One_func(root *TreeNode) int {
    res := 0
    var diving func(*TreeNode) int
    diving = func(node *TreeNode) int {
        if node == nil {
            return 0
        }
        l := diving(node.Left)
        r := diving(node.Right)
        res = max(res, l + r)
        return max(l, r) + 1
    }
    diving(root)
    return res
}

func Solution_Two_func(root *TreeNode) int {
    res := 0
    dive(root, & res)
    return res
}

func dive(node *TreeNode, res *int) int {
    if node == nil {
        return 0
    }
    l := dive(node.Left, res)
    r := dive(node.Right, res)
    *res = max(*res, l + r)
    return max(l, r) + 1
}
