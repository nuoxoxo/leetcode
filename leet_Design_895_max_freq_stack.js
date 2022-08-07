
var FreqStack = function() {
    this.count = {}
    this.group = {}
    this.max = 0
};
/** 
 * @param {number} val
 * @return {void}
 */

FreqStack.prototype.push = function(val) {
    if (val in this.count) {
        this.count[val]++
    } else {
        this.count[val] = 1
    }
    
    if (this.count[val] > this.max) {
        this.max++
    }
    
    if (this.count[val] in this.group) {
        this.group[this.count[val]].push(val)
    } else {
        this.group[this.count[val]] = [ val ]
    }
};
/**
 * @return {number}
 */

FreqStack.prototype.pop = function() {
    let res = this.group[this.max].pop()
    this.count[res]--
    if (this.group[this.max].length == 0) {
        this.max--
    }
    return res
};
/** 
 * Your FreqStack object will be instantiated and called as such:
 * var obj = new FreqStack()
 * obj.push(val)
 * var param_2 = obj.pop()
 */

