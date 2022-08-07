/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */

var addStrings = function(s1, s2) {
    len1 = s1.length
    len2 = s2.length
    diff = Math.abs(len1 - len2)
    size = Math.max(len1, len2)
    z = "0".charCodeAt(0)
    v = []
    s = ""
    if (len1 < len2)
        s1 = s1.padStart(size, '0')
    else
        s2 = s2.padStart(size, '0')
    i = size
    while (--i > -1)
        v.push(s1.charCodeAt(i) + s2.charCodeAt(i) - z * 2)
    console.log(v)
    i = -1
    while (++i < size) {
        if (v[i] > 9) {
            carry = Math.floor(v[i] / 10)
            if (i < size - 1)
                v[i + 1] += carry
            else
                v.push(carry)
            v[i] %= 10
        }
    }
    for (let n of v)
        s += String.fromCharCode(n + z)
    return s.split("").reverse().join("")
};
