/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func isPalindrome(head *ListNode) bool {
    arr := []int {}
    fst := head
    slw := head
    for fst != nil && fst.Next != nil {
        arr = append(arr, slw.Val)
        fst = fst.Next.Next
        slw = slw.Next
    }
    if fst != nil {
        slw = slw.Next
    }
    i := len(arr) - 1
    for slw != nil {
        if slw.Val != arr[i] {
            return false
        }
        slw = slw.Next
        i--
    }
    return true
}
