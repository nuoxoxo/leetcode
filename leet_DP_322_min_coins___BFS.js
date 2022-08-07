/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */

var coinChange = function(coins, n) {
    if (n == 0)
        return n
    dq = []
    seen = new Set()
    dq.push([0, 0])
    while (dq.length != 0) {
        let cur = dq[0][0]
        let lev = dq[0][1]
        if (lev != 0 && cur == n)
            return lev
        dq.shift()
        for (let c of coins) {
            if (!seen.has(c + cur) && c + cur <= n) {
                dq.push([c + cur, lev + 1])
                seen.add(c + cur)
            }
        }
    }
    return -1
};
