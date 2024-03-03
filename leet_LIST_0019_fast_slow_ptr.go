/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    s, f := head, head
    for n > 0 {
        n--
        f = f.Next
    }
    if f == nil {
        return head.Next
    }
    for f.Next != nil {
        s = s.Next
        f = f.Next
    }
    s.Next = s.Next.Next
    return head
}
