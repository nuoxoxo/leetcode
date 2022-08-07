/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function(dd, dv) {
    if (dv == 1)
        return dd
    s = (dd > 0 && dv > 0) || (dd < 0 && dv < 0) ? 1 : -1
    d = Math.abs(dd)
    v = Math.abs(dv)
    res = 0
    while (d >= v) {
        temp = v
        fact = 1
        while (d >= temp) {
            console.log(d, fact, temp)
            d -= temp
            res += fact
            fact *= 2 // fac <<= 1
            temp *= 2 // tmp <<= 1
        }
    }
    if (res > 2147483647)
        return 2147483647
    return s * res
};
