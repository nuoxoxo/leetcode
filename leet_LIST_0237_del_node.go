/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// You will not be given access to the head node
//  and it is guaranteed the given node is not the tail node

func deleteNode(node *ListNode) {
    temp := node
    temp.Val = node.Next.Val
    temp.Next = node.Next.Next
}
