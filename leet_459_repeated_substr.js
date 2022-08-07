/**
 * @param {string} s
 * @return {boolean}
 */

var repeatedSubstringPattern = function(s) {
    let ls = s + s
    ls = ls.substr(1, ls.length - 2)
    if (ls.includes(s))
        return true
    return false
};
