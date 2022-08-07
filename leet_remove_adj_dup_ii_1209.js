/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var removeDuplicates = function(s, k) {
    q = []
    for (let c of s) {
        if (q.length != 0 && c == q[0][0]) {
            if (q[0][1] == k - 1)
                q.shift()
            else
                q[0][1]++
        } else {
            q.unshift([c, 1])
        }
    }
    res = ''
    while (q.length != 0) {
        n = q.length
        while (--q[n - 1][1] > -1)
            res += q[n - 1][0]
        q.pop()
    }
    return res
};
