/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func splitListToParts(head *ListNode, k int) []*ListNode {
    res := make([]*ListNode, 0)
    size := 0
    p := head
    for p != nil {
        size++
        p = p.Next
    }
    slotSize := size / k
    remainingSlots := size % k
    p = head
    i := 0
    for i < k {
        res = append(res, p)
        tailMaybe := (*ListNode)(nil) // this line
        j := 0
        for j < slotSize {
            if p != nil {
                tailMaybe = p
                p = p.Next
                j++
            }
        }
        if p != nil && remainingSlots > 0 {
            tailMaybe = p
            p = p.Next
            remainingSlots--
        }
        if tailMaybe != nil {
            tailMaybe.Next = nil
        }
        i++
    }
    return res
}
