/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
    obj = new Object()
    obj[0] = 1
    sum = 0
    cnt = 0
    for (let n of nums) {
        sum += n
        if (sum - k in obj)
            cnt += obj[sum - k]
        if (sum in obj)
            ++ obj[sum]
        else
            obj[sum] = 1
    }
    return cnt
};
