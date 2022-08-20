/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var truncateSentence = function(s, k) {
    let r = ''
    for (let c of s) {
        if (c == ' ')
            --k
        if (k == 0)
            break
        r += c
    }
    return r
};
