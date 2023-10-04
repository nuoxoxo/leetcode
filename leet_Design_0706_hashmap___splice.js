
var MyHashMap = function() {
    this.keys = new Array()
    this.vals = new Array()
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */

MyHashMap.prototype.put = function(key, value) {
    if (this.keys.includes(key)) {
        i = this.keys.indexOf(key)
        this.vals[i] = value
        return
    }
    this.keys.push(key)
    this.vals.push(value)
};

/** 
 * @param {number} key
 * @return {number}
 */

MyHashMap.prototype.get = function(key) {
    if (this.keys.includes(key)) {
        i = this.keys.indexOf(key)
        return this.vals[i]
    }
    return -1
};

/** 
 * @param {number} key
 * @return {void}
 */

MyHashMap.prototype.remove = function(key) {
    if (this.keys.includes(key)) {
        i = this.keys.indexOf(key)
        this.vals.splice(i, 1)
        this.keys.splice(i, 1)
    }
};

/** 
 * Your MyHashMap object will be instantiated and called as such:
 * var obj = new MyHashMap()
 * obj.put(key,value)
 * var param_2 = obj.get(key)
 * obj.remove(key)
 */
