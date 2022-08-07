/**
 * @param {string} s
 * @return {number}
 */

var lengthOfLastWord = function(s) {
    let len = 0, i = s.length
    while (--i > -1) {
        if (s[i] == ' ' && len > 0)
            return len
        if (s[i] != ' ')
            len ++
    }
    return len
};
