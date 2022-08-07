/**
 * @param {number} n
 * @return {number}
 */
var countVowelStrings = function(n) {
    let a, e, i, o, u
    a = e = i = o = u = 1
    while (--n) {
        o += u
        i += o
        e += i
        a += e
    }
    return a + e + i + o + u
};
