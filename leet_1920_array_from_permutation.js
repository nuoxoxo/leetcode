/**
 * @param {number[]} nums
 * @return {number[]}
 */

var buildArray = function(nums) {
    let r = []
    for (let n of nums)
        r.push(nums[n])
    return r

};
