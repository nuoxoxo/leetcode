/**
 * @param {string} s
 * @return {string}
 */

var removeDuplicates = function(s) {
    q = []
    for (let c of s) {
        if (q.length != 0 && c == q[0])
            q.shift()
        else
            q.unshift(c)
    }
    return q.reverse().join('')
};
