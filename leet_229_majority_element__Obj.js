/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    let s = Math.floor(nums.length / 3)
    let o = new Object()
    let r = []
    for (let n of nums) {
        if (o.hasOwnProperty(n))
            ++ o[n]
        else
            o[n] = 1
    }
    for (let [i, n] of Object.entries(o)) {
        if (n > s)
            r.push(i)
    }
    return r
};
