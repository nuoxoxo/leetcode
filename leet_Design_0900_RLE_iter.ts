class RLEIterator {
    private core: number[] = []
    private size: number
    private i
    
    constructor(encoding: number[]) {
        this.core = encoding
        this.size = this.core.length
        this.i = 0
    }

    next(n: number): number {
        while (this.i < this.size - 1) {
            if (n > this.core[this.i]) {
                n -= this.core[this.i]
                this.i += 2
            } else {
                this.core[this.i] -= n
                return this.core[this.i + 1]
            }
        }
        return -1 
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * var obj = new RLEIterator(encoding)
 * var param_1 = obj.next(n)
 */
