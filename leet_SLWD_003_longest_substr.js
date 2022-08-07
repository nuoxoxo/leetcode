/**
 * @param {string} s
 * @return {number}
 */

var lengthOfLongestSubstring = function(s) {
    let len = s.length
    let E = new Set()
    let res = 0, i = 0, j = -1
    while (++j < len) {
        while (E.has(s[j])) {
            E.delete(s[i])
            ++i
        }
        E.add(s[j])
        res = Math.max(j - i + 1, res)
    }
    return res
};
