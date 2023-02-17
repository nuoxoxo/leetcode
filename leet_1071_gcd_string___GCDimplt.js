/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */

var gcdOfStrings = function(s1, s2) {
    if (s1 + s2 != s2 + s1)
        return ''
    let len1 = s1.length, len2 = s2.length
    let len = GCD(len1, len2)
    let s = len1 > len2 ? s1 : s2
    let i = -1
    let r = ''
    while (++i < len) {
        r += s[i]
    }
    return r
};

var GCD = function(a, b) {
    let g = Math.min(a, b)
    while (g > 0) {
        if (a % g == 0 && b % g == 0)
            break
        --g
    }
    return g
}
