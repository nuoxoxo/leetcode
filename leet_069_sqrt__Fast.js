/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    mid = Math.floor(x / 2)
    res = 0
    L = 0
    R = x
    while (L <= R) {
        temp = mid * mid
        if (x == temp)
            return mid
        else if (temp > x)
            R = mid - 1
        else {
            res = mid
            L = mid + 1
        }
        mid = Math.floor((R - L) / 2) + L
    }
    return res
};
