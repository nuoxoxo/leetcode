/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var findKthPositive = function(arr, k) {
    for (let n of arr) {
        if (n <= k)
            k++
    }
    return k
};
