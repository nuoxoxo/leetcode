type RLEIterator struct {
    core [] int
    size int
    i int
}


func Constructor(encoding []int) RLEIterator {
    return RLEIterator {
        core: encoding,
        size: len(encoding),
        i: 0,
    }
}


func (this *RLEIterator) Next(n int) int {
    for this.i < this.size - 1 {
        if n > this.core[this.i] {
            n -= this.core[this.i]
            this.i += 2
        } else {
            this.core[this.i] -= n
            return this.core[this.i + 1]
        }
    }
    return -1
}


/**
 * Your RLEIterator object will be instantiated and called as such:
 * obj := Constructor(encoding);
 * param_1 := obj.Next(n);
 */
