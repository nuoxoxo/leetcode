type Node struct {

    Val     int
    Next    * Node
}

//

type MyLinkedList struct {

    Head    * Node
    Size    int
}


func Constructor() MyLinkedList {

    return MyLinkedList {
        Head: nil,
        Size: 0,
    }
}


func (this *MyLinkedList) Get(index int) int {

    if index < 0 || index > this.Size - 1 {
        return -1
    }
    node := this.Head
    i := 0
    for i < index {
        node = node.Next
        i++
    }
    return node.Val
}


func (this *MyLinkedList) AddAtHead(val int)  {

    new_head := & Node { Val: val, Next: nil }
    new_head.Next = this.Head
    this.Head = new_head
    this.Size++
}


func (this *MyLinkedList) AddAtTail(val int)  {

    if this.Head == nil {
        this.Head = & Node {Val: val, Next: nil}
        this.Size = 1
        return
    }
    node := this.Head
    for node.Next != nil {
        node = node.Next
    }
    node.Next = & Node {Val: val, Next: nil}
    this.Size++
}


func (this *MyLinkedList) AddAtIndex(index int, val int)  {
    if index < 0 || index > this.Size {
        return
    }
    todo := & Node {Val: val, Next: nil}
    if index < 1 {
        todo.Next = this.Head
        this.Head = todo
        this.Size++
        return
    }
    node := this.Head
    i := 0
    for i < index - 1 {
        node = node.Next
        i++
    }
    todo.Next = node.Next
    node.Next = todo
    this.Size++
}


func (this *MyLinkedList) DeleteAtIndex(index int)  {

    if index < 0 || index > this.Size - 1 {
        return
    }
    if index == 0 {
        this.Head = this.Head.Next
        this.Size--
        return
    }
    node := this.Head
    i := 0
    for i < index - 1 {
        node = node.Next
        i++
    }
    node.Next = node.Next.Next
    this.Size--
}


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Get(index);
 * obj.AddAtHead(val);
 * obj.AddAtTail(val);
 * obj.AddAtIndex(index,val);
 * obj.DeleteAtIndex(index);
 */
