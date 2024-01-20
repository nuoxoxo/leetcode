/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reorderList(head *ListNode)  {
    if head == nil || head.Next == nil || head.Next.Next == nil {
        return
    }
    dq := []*ListNode{}
    node := head
    size := 0
    for node != nil {
        dq = append( dq, node )
        node = node.Next
        size += 1
    }
    i := 0
    node = head
    for i < size / 2 {
        new_node := dq[len(dq) - 1]
        dq = dq[:len(dq) - 1]
        new_node.Next = node.Next
        node.Next = new_node
        node = node.Next.Next
        i += 1
    }
    node.Next = nil
}
