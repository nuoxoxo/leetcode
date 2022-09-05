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
    r = append(r, [] int { root.Val })
    dq = append(dq, root)
    for len(dq) > 0 {
        temp := [] int {}
        size := len(dq)
        for i := 0; i < size; i++ {
            node := dq[0]
            dq = dq[1:]
            for _, child := range node.Children {
                dq = append(dq, child)
                temp = append(temp, child.Val)
            }
        }
        if len(temp) != 0 {
            r = append(r, temp)
        }
    }
    return r
}
