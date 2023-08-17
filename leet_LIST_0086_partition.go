/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
    if head == nil {
        return head
    }

    var L, R []int
    p := head

    for p != nil {
        n := p.Val
        if n < x {
            L = append(L, n)
        } else {
            R = append(R, n)
        }
        p = p.Next
    }

    p = head
    for _, n := range L {
        p.Val = n
        p = p.Next
    }

    for _, n := range R {
        p.Val = n
        p = p.Next
    }

    return head
}
