/**
 * @param {number[]} arr
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findClosestElements = function(arr, k, x) {
    n = arr.length
    right = n - 1
    left = 0
    while (left < right && n > k) {
        if (Math.abs(arr[left] - x) > Math.abs(arr[right] - x)) {
            ++left
        } else {
            --right
        }
        --n
    }
    res = []
    while (left < right + 1) {
        res.push(arr[left++])
    }
    return res
};
