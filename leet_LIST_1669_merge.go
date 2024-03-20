/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
    head := list1
    p1a, p1b := head, head
    p2end := list2
    for a > 1 && p1a != nil {
        a--
        b--
        p1a = p1a.Next
        p1b = p1b.Next
    }
    for b > -1 && p1b != nil {
        b--
        p1b = p1b.Next
    }
    if a != 1 || b != -1 {
        panic(fmt.Sprintf("/a %d - /b %d", a, b))
    }
    for p2end.Next != nil {
        p2end = p2end.Next
    }
    p1a.Next, p2end.Next = list2, p1b
    return head
}
