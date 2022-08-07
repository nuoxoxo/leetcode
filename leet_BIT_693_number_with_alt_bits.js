/**
 * @param {number} n
 * @return {boolean}
 */
var hasAlternatingBits = function(n) {
    cmp = n % 2
    while (n != 0) {
        if (cmp != n % 2)
            return false
        cmp = cmp == 1 ? 0 : 1
        n >>= 1
    }
    return true
};
