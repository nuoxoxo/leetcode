/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {

    Solutions := []func(*ListNode) *ListNode {
        // Naive,
        Fast_and_slow_pointers,
    }
    return Solutions[0](head)
}

func Fast_and_slow_pointers(head *ListNode) *ListNode {

    f,s := head, head
    for f != nil && f.Next != nil {
        f = f.Next.Next
        s = s.Next
    }
    if f != nil && f.Next != nil {
        s = s.Next
    }
    return s
}

func Naive(head *ListNode) *ListNode {
    size := 0
    node := head
    for node != nil {
        node = node.Next
        size++
    }
    node = head
    size /= 2
    for size > 0 {
        node = node.Next
        size--
    }
    return node
}
