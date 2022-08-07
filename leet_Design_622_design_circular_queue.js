/**
 * @param {number} k
 */
var MyCircularQueue = function(k) {
    this.lim = k
    this.arr = []
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularQueue.prototype.enQueue = function(value) {
    if (this.arr.length != this.lim) {
        this.arr.push(value)
        return true
    }   return false
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.deQueue = function() {
    if (this.arr.length) {
        this.arr.shift()
        return true
    }   return false
};

/**
 * @return {number}
 */
MyCircularQueue.prototype.Front = function() {
    if (this.arr.length)
        return this.arr[0]
    return -1
};

/**
 * @return {number}
 */
MyCircularQueue.prototype.Rear = function() {
    let n = this.arr.length
    if (n)
        return this.arr[n - 1]
    return -1
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.isEmpty = function() {
    return this.arr.length === 0
};

/**
 * @return {boolean}
 */
MyCircularQueue.prototype.isFull = function() {
    return this.arr.length === this.lim
};

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
