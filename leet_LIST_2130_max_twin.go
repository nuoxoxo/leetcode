/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func pairSum(head *ListNode) int {

    Solutions := []func(*ListNode) int {
        // Reverse_linked_list,
        Using_extra_slice,
    }
    return Solutions[0](head)
}

func Reverse_linked_list(head *ListNode) int {

    f,s := head, head
    var rev * ListNode = nil
    for f != nil && f.Next != nil {
        f = f.Next.Next
        nxt := s.Next
        s.Next = rev
        rev = s
        s = nxt
    }
    if f != nil {
        s = s.Next
    }
    res := 0
    for rev != nil && s != nil {
        temp := rev.Val + s.Val
        if res < temp {
            res = temp
        }
        rev = rev.Next
        s = s.Next
    }
    return res
}

func Using_extra_slice(head *ListNode) int {

    f,s := head, head
    A := []int{}
    for f != nil && f.Next != nil {
        A = append(A, s.Val)
        f = f.Next.Next
        s = s.Next
    }
    if f != nil {
        s = s.Next
    }
    res := 0
    i := len(A) - 1
    for s != nil {
        temp := A[i] + s.Val
        if res < temp {
            res = temp
        }
        s = s.Next
        i--
    }
    return res
}
