/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    if head == nil {
        return head
    }
    var self *ListNode = head
    // prev := nil
    // next := nil
    var prev *ListNode = nil
    var next *ListNode = nil
    for self != nil {
        next = self.Next
        self.Next = prev
        prev = self
        self = next
    }
    head = prev
    return head
}
