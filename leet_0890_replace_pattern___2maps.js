/**
 * @param {string[]} words
 * @param {string} pattern
 * @return {string[]}
 */
var findAndReplacePattern = function(words, pattern) {
    let     res = []

    for (let w of words) {
        if (valid(w, pattern))
            res.push(w)
    }
    return res
};

function    valid (w, p) {
    let     W = new Array(26).fill(-1)
    let     P = new Array(26).fill(-1)
    let     len = w.length
    let     i = -1
    let     a = 'a'.charCodeAt(0)
    while (++i < len) {
        let cw = w[i]
        let cw_code = cw.charCodeAt(0)
        let cp = p[i]
        let cp_code = cp.charCodeAt(0)
        if (W[cw_code - a] < 0)
            W[cw_code - a] = cp
        if (P[cp_code - a] < 0)
            P[cp_code - a] = cw
        if (W[cw_code - a] != cp || P[cp_code - a] != cw)
            return false
    }
    return true
}
