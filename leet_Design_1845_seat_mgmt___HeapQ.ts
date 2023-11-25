class SeatManager {

    prev = 0 // class property
    heap = []

    constructor(n: number) {
        this.prev = 0
        this.heap = []
    }

    reserve(): number {
        if (this.heap.length == 0)
            return ++this.prev
        this.heap.sort((a, b) => a - b)
        return this.heap.shift()
    }

    unreserve(seatNumber: number): void {
        if (seatNumber === this.prev)
            this.prev--
        else
            this.heap.push( seatNumber )
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * var obj = new SeatManager(n)
 * var param_1 = obj.reserve()
 * obj.unreserve(seatNumber)
 */
