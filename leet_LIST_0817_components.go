/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func numComponents(head *ListNode, nums []int) int {
    res := 0
    cut := 1
    set := map[int]bool{}
    for _, n := range nums { set[n] = true }
    for head != nil {
        if set[head.Val] {
            if cut == 1 {
                res++
            }
            cut = 0
        } else {
            cut = 1
        }
        head = head.Next
    }
    return res
}
