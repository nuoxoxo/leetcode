/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */

var strStr = function(haystack, needle) {
    let sn = needle.length
    if (sn == 0)
        return sn
    let sh = haystack.length
    let i = -1
    if ((sh == 0) || sn > sh)
        return i
    while (++i < sh - sn + 1) {
        if (haystack.substr(i, sn) == needle)
            return i
    }
    return -1
};
