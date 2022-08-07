/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxOperations = function(n, k) {
    n.sort((a, b) => a - b)
    i = 0
    j = n.length - 1
    res = 0
    while (i < j && n[i] < k) {
        if (n[i] + n[j] < k) {
            ++i
        } else if (n[i] + n[j] > k) {
            --j
        } else {
            ++res
            ++i
            --j
        }
    }
    return res
};
