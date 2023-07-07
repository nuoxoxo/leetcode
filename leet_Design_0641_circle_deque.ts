class MyCircularDeque {

    private dq: number[]
    private L: number
    private R: number

    // private K: number

    constructor(k: number) {
        this.dq = new Array(k).fill(0 /* null */)
        this.L = -1
        this.R = -1
    }

    insertFront(value: number): boolean {
        if (this.isFull()) {
            return false
        }

        if (this.L != -1) {
            this.L += this.dq.length - 1
            this.L %= this.dq.length
            this.dq[this.L] = value
            // console.log(this.dq)            
        } else {
            this.insertLast(value)
        }

        return true
    }

    deleteFront(): boolean {
        if (this.isEmpty()) {
            return false
        }
        if (this.L != this.R) {
            this.L += 1
            this.L %= this.dq.length
        } else {
            // empty array after shift/pop_front
            this.L = -1
            this.R = -1
        }

        // console.log(this.dq)
        return true
    }

    insertLast(value: number): boolean {
        if (this.isFull()) {
            return false
        }

        if (this.L === -1) {
            this.L = 0
        }

        this.R += 1
        this.R %= this.dq.length
        this.dq[this.R] = value

        // console.log(this.dq)
        return true
    }

    deleteLast(): boolean {
        if (this.isEmpty()) {
            return false
        }

        if (this.L != this.R) {
            this.R += this.dq.length - 1
            this.R %= this.dq.length
        } else {
            this.L = this.R = -1
        }

        // console.log(this.dq)
        return true
    }

    getFront(): number {
        if (this.isEmpty()) {
            return -1
        }
        return this.dq[this.L]!
    }

    getRear(): number {
        if (this.isEmpty()) {
            return -1
        }
        // console.log(this.dq)
        return this.dq[this.R]!
    }

    isEmpty(): boolean {
        return (this.L === -1 && this.R === -1)
    }

    isFull(): boolean {
        return (this.R + 1) % this.dq.length === this.L 
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * var obj = new MyCircularDeque(k)
 * var param_1 = obj.insertFront(value)
 * var param_2 = obj.insertLast(value)
 * var param_3 = obj.deleteFront()
 * var param_4 = obj.deleteLast()
 * var param_5 = obj.getFront()
 * var param_6 = obj.getRear()
 * var param_7 = obj.isEmpty()
 * var param_8 = obj.isFull()
 */
