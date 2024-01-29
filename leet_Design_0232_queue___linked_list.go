// added struct : Node

type (
    Node struct {
        Val int
        Next * Node
    }
    MyQueue struct {
        Head * Node
        Tail * Node
    }
)

/*
type Node struct {
    Val int
    Next * Node
}
type MyQueue struct {
    Head * Node
    Tail * Node
}
*/

func Constructor() MyQueue {

    return MyQueue{} // return this _init empty_ //
}


func (this *MyQueue) Push(x int)  {

    node := & Node {Val: x}
    if this.Tail != nil {
        this.Tail.Next = node // append
        this.Tail = node // tail advanced one node
    } else {
        this.Head = node
        this.Tail = node
    }
}


func (this *MyQueue) Pop() int {

    if this.Empty() {
        panic("/assert: list not empty when pop()")
    }
    val := this.Head.Val
    this.Head = this.Head.Next
    if this.Head == nil { // its only node has been popped
        this.Tail = nil
    }
    return val
}


func (this *MyQueue) Peek() int {
    if this.Empty() {
        panic("/assert: list not empty when peek()")
    }
    return this.Head.Val
}


func (this *MyQueue) Empty() bool {
    return this.Head == nil
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
