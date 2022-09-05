/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func levelOrder(root *Node) [][]int {
    r := [][] int {}
    dq := [] *Node {}
    if root == nil {
        return r
    }
    dq = append(dq, root)
    for len(dq) > 0 {
        temp := [] int {}
        size := len(dq)
        for i := 0; i < size; i++ {
            node := dq[0]
            dq = dq[1:]
            temp = append(temp, node.Val)
            for _, child := range node.Children {
                dq = append(dq, child)
            }
        }
        r = append(r, temp)
    }
    return r
}
