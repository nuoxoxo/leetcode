// import {
//     "list/List"
// }

type MyQueue struct {

    lst list.List
}


func Constructor() MyQueue {

    return MyQueue{}
}


func (this *MyQueue) Push(x int)  {

    this.lst.PushBack(x)
}


func (this *MyQueue) Pop() int {

    if this.Empty() {
        panic("/assert: pop empty")
    }
    val := this.lst.Front().Value.(int)
    this.lst.Remove( this.lst.Front() )
    return val
}


func (this *MyQueue) Peek() int {
    return this.lst.Front().Value.(int)
}


func (this *MyQueue) Empty() bool {

    return this.lst.Len() == 0
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
