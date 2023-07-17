/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var L []int
    var R []int
    for l1 != nil {
        L = append(L, l1.Val)
        l1 = l1.Next
    }
    for l2 != nil {
        R = append(R, l2.Val)
        l2 = l2.Next
    }

    var res *ListNode
    var carry int = 0
    for carry != 0 || len(L) != 0 || len(R) != 0 {
        var l, r int
        if len(L) == 0 {
            l = 0
        } else {
            l = L[len(L) - 1]
            L = L[:len(L) - 1]
        }
        if len(R) == 0 {
            r = 0
        } else {
            r = R[len(R) - 1]
            R = R[:len(R) - 1]
        }

        // var node ListNode = & ListNode { (l + r + carry) % 10, nil  }
        node := & ListNode { (l + r + carry) % 10, nil  }
        carry = (l + r + carry) / 10
        node.Next = res
        res = node
    }
    return res
}
