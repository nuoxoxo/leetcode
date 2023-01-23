/**
 * @param {number} n
 * @param {number[][]} trust
 * @return {number}
 */

var findJudge = function(n, trust) {
    rr = new Array(n).fill(0)
    cc = new Array(n).fill(0)
    for (let t of trust) {
        rr[t[0] - 1]++
        cc[t[1] - 1]++
    }
    i = -1
    while (++i < n) {
        if (rr[i] == 0 && cc[i] == n - 1)
            return i + 1
    }
    return -1
};
