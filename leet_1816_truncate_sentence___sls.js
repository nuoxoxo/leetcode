/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var truncateSentence = function(s, k) {
    r = s.split(' ')
    s = ''
    for (let w of r) {
        if (k-- == 0)
            break
        s += w + ' '
    }
    return s.slice(0, -1)
};
