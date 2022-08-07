
var MyCalendar = function() {
    this.mp = []
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {boolean}
 */
MyCalendar.prototype.book = function(start, end) {
    for (let p of this.mp) {
        if (!(p[0] > end - 1 || p[1] < start))
            return false
    }
    this.mp.push([start, end - 1])
    return true
};

/** 
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = new MyCalendar()
 * var param_1 = obj.book(start,end)
 */
