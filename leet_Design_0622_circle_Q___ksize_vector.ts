class MyCircularQueue {
    private dq: Array<number | null>
    private curr: number
    private size: number
    private K: number
    
    constructor(k: number) {
        this.dq = new Array(k).fill(null)
        this.curr = 0
        this.size = 0
        this.K = k
    }

    enQueue(value: number): boolean {
        if (this.isFull()) {
            return false
        }
        this.dq[(this.curr + this.size) % this.K] = value
        this.size++
        return true
    }

    deQueue(): boolean {
        if (this.isEmpty()) {
            return false
        }
        
        this.curr = (this.curr + 1) % this.K
        this.size--
        return true
    }

    Front(): number {
        if (this.isEmpty()) {
            return -1
        }
        return this.dq[this.curr]!
    }

    Rear(): number {
        if (this.isEmpty()) {
            return -1
        }
        let dest = (this.curr + this.size - 1) % this.K
        return this.dq[dest]! // ! is a non-null assertion operator
        //  `!` tell the compiler that a value will not be null | undefined at runtime
        //  even though it does not seems that way
    }

    isEmpty(): boolean {
        return this.size === 0
    }

    isFull(): boolean {
        return this.size === this.K
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * var obj = new MyCircularQueue(k)
 * var param_1 = obj.enQueue(value)
 * var param_2 = obj.deQueue()
 * var param_3 = obj.Front()
 * var param_4 = obj.Rear()
 * var param_5 = obj.isEmpty()
 * var param_6 = obj.isFull()
 */
