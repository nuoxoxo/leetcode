type MyQueue []int


func Constructor() MyQueue {

    return MyQueue{} // return this _init empty_ //
}


func (this *MyQueue) Push(x int)  {

    *this = append( *this, x )
}


func (this *MyQueue) Pop() int {

    res := (*this)[0]
    (*this) = (*this)[1:]
    return res
}


func (this *MyQueue) Peek() int {

    return (*this)[0]
}


func (this *MyQueue) Empty() bool {

    return len(*this) == 0
}


/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
