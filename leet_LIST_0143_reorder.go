/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reorderList(head *ListNode)  {

    Solutions := []func(*ListNode) {
        Using_reverse_linked_list,
    }
    Solutions[0](head)
}

func Using_reverse_linked_list(head *ListNode)  {
    if head == nil || head.Next == nil {
        return
    }
    f, s := head, head
    for f != nil && f.Next != nil {
        f = f.Next.Next
        s = s.Next
    }
    var end *ListNode = s
    var nxt *ListNode
    nxt = s.Next
    s.Next = nil
    s = nxt
    // fmt.Println("/cut", s.Val) // OK
    for s != nil {
        nxt = s.Next
        s.Next = end
        end = s
        s = nxt
    }
    s = head
    // fmt.Println(end.Val, end.Next.Val) // OK
    for s != nil && end != nil && s != end && s.Next != end {
        // fmt.Println(s.Val, end.Val)
        nxt = s.Next
        if nxt == nil {
            break
        }
        new_node := &ListNode{Val:end.Val, Next:nxt}
        s.Next = new_node
        s = nxt//s.Next.Next
        end = end.Next
    }
}

func Extra_space(head *ListNode)  {
    if head == nil || head.Next == nil {
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
