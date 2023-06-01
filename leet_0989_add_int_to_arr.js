/**
 * @param {number[]} num
 * @param {number} k
 * @return {number[]}
 */

var addToArrayForm = function(num, k) {
    let i = num.length
    let r = []
    while (--i > -1 || k != 0) {
        if (i > -1)
            k += num[i]
        r.push(k % 10)
        k = Math.floor(k / 10)
    }
    return r.reverse()
};
