/**
 * @param {number} n
 * @return {number}
 */

var arrangeCoins = function(n) {
    let i = 0
    while (++i) {
        if (i + 1 > n)
            break
        n -= i
    }
    if (i == n)
        return i
    return i - 1
};
