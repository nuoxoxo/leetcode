/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {

    Solutions := []func( * ListNode) * ListNode {
        reverse_linked_list,
        // space_heavy,
    }
    return Solutions[ 0 ]( head )
}

func reverse_linked_list (head * ListNode) * ListNode {

    if head == nil {
        return head
    }
    var curr * ListNode = head
    var prev * ListNode = nil
    var next * ListNode = nil
    for curr != nil {
        next = curr.Next // preserve the Next-ptr
        curr.Next = prev // reverse this node by re-assigning its Next-pointer
        prev = curr // move rightwards
        curr = next // move rightwards
    }
    return prev
}

func space_heavy (head * ListNode) * ListNode {

    if head == nil {
        return head
    }
    arr := []int{}
    var p *ListNode = head
    for p != nil {
        arr = append(arr, p.Val)
        p = p.Next
    }
    p = & ListNode{
        Val: 0,
        Next: nil,
    }
    var res *ListNode = p
    i := len(arr) - 1
    for i > -1 {
        var node *ListNode = &ListNode{
            Val: arr[i],
            Next: nil,
        }
        p.Next = node
        p = p.Next
        i--
    }
    return res.Next
}

