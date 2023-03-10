/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type Solution struct {
    a [] int // strange syntax
}


func Constructor(head *ListNode) Solution {
    a := [] int {} // strange syntax
    p := head
    for p != nil {
        a = append(a, p.Val)
        p = p.Next
    }
    return Solution {a} // strange syntax
}


func (this *Solution) GetRandom() int {
    return this.a[rand.Intn(len(this.a))]
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(head);
 * param_1 := obj.GetRandom();
 */
