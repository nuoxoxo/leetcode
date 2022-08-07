/**
 * @param {number} num
 * @param {number} k
 * @return {number}
 */
var divisorSubstrings = function(num, k) {
    let s = num.toString()
    let len = s.length
    let i = -1, j = 0
    while (++i < len - k + 1) {
        let tmp = parseInt(s.substring(i, i + k))
        if (tmp > 0 && num % tmp == 0)
            ++c
    }
    return c
};
