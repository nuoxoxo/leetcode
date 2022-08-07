/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(n) {
    let sum = n.reduce((s, a) => s + a, 0);
    let cur = 0
    let i = -1
    while (++i < n.length){
        if (i)
            cur += n[i - 1]
        if (cur == (sum - n[i]) / 2)
            return i
    }
    return -1
};
