/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNodes(head *ListNode) *ListNode {

    solutions := []func(*ListNode) *ListNode {
        // popping_monostack,
        reverse_reverse,
    }
    return solutions[0](head)
}

func reverse_reverse(head *ListNode) *ListNode {

    var reverse_llist func(*ListNode) *ListNode
    reverse_llist = func(head *ListNode) *ListNode {
        // pprev, pnext := nil, nil
        var pprev, pnext *ListNode
        node := head
        for node != nil {
            pnext = node.Next
            node.Next = pprev
            pprev = node
            node = pnext
        }
        return pprev
    }
    new_list := reverse_llist(head)
    node := new_list
    for node.Next != nil {
        if node.Val > node.Next.Val {
            node.Next = node.Next.Next
        } else {
            node = node.Next
        }
    }
    return reverse_llist(new_list)
}

func popping_monostack(head *ListNode) *ListNode {

    dummy := &ListNode{ Val: 2147483647 }
    D := []*ListNode{ dummy }
    node := head
    for node != nil {
        for D[len(D) - 1].Val < node.Val {
            D = D[:len(D) - 1]
        }
        D[len(D) - 1].Next = node
        D = append(D, node)
        node = node.Next
    }
    return dummy.Next
}


