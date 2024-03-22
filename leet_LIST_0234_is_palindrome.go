/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {

    Solutions := []func(*ListNode)bool{
        // Compare_to_half_array,
        Reverse_linked_list,
    }
    return Solutions[0](head)
}

func Reverse_linked_list(head *ListNode) bool {
    f,s := head, head
    var rev *ListNode = nil
    for f != nil && f.Next != nil {
        f = f.Next.Next
        nxt := s.Next // save the next pointer for later
        s.Next = rev // reverse next pointer for this node
        rev = s // move eastwards
        s = nxt // move eastwards
    }
    if f != nil {
        s = s.Next
    }
    for rev != nil && s != nil {
        if rev.Val != s.Val {
            return false
        }
        rev = rev.Next
        s = s.Next
    }
    return true
}

func Compare_to_half_array(head *ListNode) bool {
    f,s := head, head
    half := []int{}
    for f != nil && f.Next != nil {
        half = append(half, s.Val)
        f = f.Next.Next
        s = s.Next
    }
    if f != nil {
        s = s.Next
    }
    i := len(half) - 1
    for s != nil {
        if s.Val != half[i] {
            return false
        }
        s = s.Next
        i--
    }
    return true
}
