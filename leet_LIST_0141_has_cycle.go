/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    if head == nil {
        return false
    }
    s := head
    f := head
    for f != nil && f.Next != nil {
        f = f.Next.Next
        s = s.Next
        if s == f {
            return true
        }
    }
    return false
}
