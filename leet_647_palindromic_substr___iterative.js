/**
 * @param {string} s
 * @return {number}
 */

var countSubstrings = function(s) {
    let len = s.length
    if (len == 0 || len == 1)
        return len
    let res = 0
    let i, j, k
    i = -1
    while (++i < len) {
        j = k = i
        while (j > -1 && k < len) {
            if (s[j] == s[k]) {
                ++res
                --j
                ++k
            } else {
                break
            }
        }
    }
    i = -1
    while (++i < len) {
        j = i
        k = i + 1
        while (j > -1 && k < len) {
            if (s[j] == s[k]) {
                ++res
                --j
                ++k
            } else {
                break
            }
        }
    }
    return res
};
