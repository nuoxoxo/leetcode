/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeNodes(head *ListNode) *ListNode {
    fast := head.Next
    slow := head
    temp := 0
    for fast != nil {
        if fast.Val != 0 {
            temp += fast.Val
        } else {
            slow = slow.Next
            slow.Val = temp
            temp = 0
        }
        fast = fast.Next
    }
    slow.Next = nil
    return head.Next
}
