/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */

var divide = function(dd, dv) {
    if (dv == 1)
        return dd
    sgn = (dd > 0 && dv > 0) || (dd < 0 && dv < 0) ? 1 : -1
    res = Math.floor(Math.abs(dd) / Math.abs(dv))
    if (res > 2147483647)
        return 2147483647
    return res * sgn
};
