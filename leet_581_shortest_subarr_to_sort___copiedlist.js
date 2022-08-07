/**
 * @param {number[]} nums
 * @return {number}
 */
var findUnsortedSubarray = function(nums) {
    temp = [...nums]
    temp.sort((a, b) => a - b)
    n = nums.length
    mk = 0 // mark
    i = -1
    while (++i < n) {
        if (nums[i] != temp[i]) {
            mk = i;
            break;
        }
    }
    i = n
    while (--i > -1) {
        if (nums[i] != temp[i]) {
            return i + 1 - mk
        }
    }
    return mk
};
