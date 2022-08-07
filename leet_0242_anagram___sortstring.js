/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    ss = s.split('').sort().join('')
    tt = t.split('').sort().join('')
    return ss == tt
};
