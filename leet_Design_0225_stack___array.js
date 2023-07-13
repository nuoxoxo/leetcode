
var MyStack = function() {
    this.q = []
};

/** 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.q.unshift(x)
};

/**
 * @return {number}
 */
MyStack.prototype.pop = function() {
    let n = this.q[0]
    this.q.shift()
    return n
};

/**
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.q[0]
};

/**
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.q.length == 0
};

/** 
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */
