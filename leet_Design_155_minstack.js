
var MinStack = function() {
    this.s = [] // main stack
    this.m = [] // min stack
    
};

/** 
 * @param {number} val
 * @return {void}
 */

MinStack.prototype.push = function(val) {
    if (this.s.length == 0 || val <= this.m[0])
        this.m.unshift(val)
    this.s.unshift(val)
};

/**
 * @return {void}
 */

MinStack.prototype.pop = function() {
    if (this.m[0] == this.s[0])
        this.m.shift()
    this.s.shift()
};

/**
 * @return {number}
 */

MinStack.prototype.top = function() {
    return this.s[0]
};

/**
 * @return {number}
 */

MinStack.prototype.getMin = function() {
    return this.m[0]
};

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
