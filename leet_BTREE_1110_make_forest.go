/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func delNodes(root *TreeNode, to_delete []int) []*TreeNode {
    Solutions := []func(*TreeNode, []int) []*TreeNode {
        // FillForest,
        delNodesMakeForest,
    }
    return Solutions[0](root, to_delete)
}

func delNodesMakeForest(root *TreeNode, to_delete []int) []*TreeNode {

    var contains func(int, []int) bool
    contains = func(tar int, arr[]int) bool {
        for _, elem := range arr {
            if elem == tar {
                return true
            }
        }
        return false
    }

    res := []*TreeNode{}
    var DFS func(*TreeNode, bool)

    DFS = func(node * TreeNode, hasParent bool) {
        if node == nil {
            return
        }
        new_parent := node
        validParent := true
        if contains(node.Val, to_delete) {
            new_parent = nil
            validParent = false
        }
        if new_parent != nil && !hasParent {
            res = append(res, new_parent)
        }
        DFS(node.Left, validParent)
        DFS(node.Right, validParent)
        if node.Left != nil && contains(node.Left.Val, to_delete) {
            node.Left = nil
        }
        if node.Right != nil && contains(node.Right.Val, to_delete) {
            node.Right = nil
        }
    }
    DFS(root, false)
    return res
}

func FillForest(root *TreeNode, to_delete []int) []*TreeNode {

    var contains func(int, []int) bool
    contains = func(tar int, arr[]int) bool {
        for _, elem := range arr {
            if elem == tar {
                return true
            }
        }
        return false
    }

    res := []*TreeNode{}
    var DFS func(*TreeNode, bool) *TreeNode

    DFS = func(node * TreeNode, hasParent bool) *TreeNode {
        if node == nil {
            return nil
        }
        new_parent := node
        validParent := true
        if contains(node.Val, to_delete) {
            new_parent = nil
            validParent = false
        }
        if new_parent != nil && !hasParent {
            res = append(res, new_parent)
        }
        node.Left = DFS(node.Left, validParent)
        node.Right = DFS(node.Right, validParent)
        return new_parent
    }
    DFS(root, false)
    return res
}

