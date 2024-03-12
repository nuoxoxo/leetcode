/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeZeroSumSublists(head *ListNode) *ListNode {
    dummy := & ListNode {Val: 0, Next: head}
    node := dummy
    prefix := 0
    D := map[int] * ListNode {0: head}
    for node != nil {
        prefix += node.Val
        D[prefix] = node // constantly updating
        node = node.Next
    }
    prefix = 0
    node = dummy
    for node != nil {
        prefix += node.Val
        // in D such prefix must exsits and might be updated previously
        next, ok := D[ prefix ]
        if ok {
            node.Next = next.Next
            node = node.Next
        }
    }
    return dummy.Next
}
