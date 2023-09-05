/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    E := make( map[ *Node ] *Node )
    curr := head
    for curr != nil {
        temp := & Node { Val: curr.Val}
        E[curr] = temp
        curr = curr.Next
    }
    curr = head
    for curr != nil {
        ptr := E[curr]
        ptr.Next = E[curr.Next]
        ptr.Random = E[curr.Random]
        curr = curr.Next
    }
    return E[head]
}
