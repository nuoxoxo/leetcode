/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let res, o, c
    res = o = c = 0
    for (let ch of s) {
        if (ch == '(') {
            ++o
        } else {
            ++c
        }
        if (o < c) {
            o = c = 0
        } else if (o == c) {
            res = Math.max(o + c, res)
        }
    }
    o = c = 0
    s = s.split('').reverse().join('')
    console.log(s)
    for (let ch of s) {
        if (ch == '(') {
            ++o
        } else {
            ++c
        }
        if (o > c) {
            o = c = 0
        } else if (o == c) {
            res = Math.max(o + c, res)
        }
    }
    return res
};
