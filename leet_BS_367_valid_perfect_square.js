/**
 * @param {number} num
 * @return {boolean}
 */

var isPerfectSquare = function(num) {
    L = 0
    R = num
    while (L <= R) {
        mid = Math.floor((R + L) / 2)
        msq = mid * mid
        if (msq == num)
            return true
        if (msq < num)
            L = mid + 1
        if (msq > num)
            R = mid - 1
    }
    return false
};
