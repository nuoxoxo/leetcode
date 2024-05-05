type Node struct {

    Url     string
    Prev    * Node
    Next    * Node
}

type BrowserHistory struct {

    Curr * Node
}


func Constructor(homepage string) BrowserHistory {

    return BrowserHistory {
        Curr: & Node {
            Url:    homepage,
            Prev:   nil,
            Next:   nil,
        },
    }
}


func (this *BrowserHistory) Visit(url string)  {

    // clears up all the forward history
    //  1. create a next - set next's prev to curr
    //  2. move to the next
    //  (returns nothing)

    nxt := & Node {
        Url:    url,
        Prev:   this.Curr,
    }
    this.Curr.Next = nxt
    this.Curr = this.Curr.Next
}


func (this *BrowserHistory) Back(steps int) string {

    // can only go back (x < steps) steps in the history
    //  - move to min(steps ahead, list tail)
    //  - returns a URL

    for this.Curr.Prev != nil && steps > 0 {
        this.Curr = this.Curr.Prev
        steps -= 1
    }
    return this.Curr.Url
}


func (this *BrowserHistory) Forward(steps int) string {

    // same as Back()

    for this.Curr.Next != nil && steps > 0 {
        this.Curr = this.Curr.Next
        steps -= 1
    }
    return this.Curr.Url
}


/**
 * Your BrowserHistory object will be instantiated and called as such:
 * obj := Constructor(homepage);
 * obj.Visit(url);
 * param_2 := obj.Back(steps);
 * param_3 := obj.Forward(steps);
 */
