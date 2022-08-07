/**
 * @param {number[]} nums
 */

var NumArray = function(nums) {
    this.len = nums.length
    this.pfs = []
    this.pfs.push(nums[0])
    let i = 0
    while (++i < this.len) {
        this.pfs.push(nums[i])
        this.pfs[i] += this.pfs[i - 1]
    }
};

/** 
 * @param {number} left 
 * @param {number} right
 * @return {number}
 */

NumArray.prototype.sumRange = function(left, right) {
    if (left > this.len - 1)
        return 0
    let r = (right < this.len - 1) ? right : this.len - 1
    let res = this.pfs[r]
    if (left == 0)
        return res
    return (res - this.pfs[left - 1])
};

/** 
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(left,right)
 */
