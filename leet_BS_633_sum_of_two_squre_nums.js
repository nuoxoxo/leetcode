/**
 * @param {number} c
 * @return {boolean}
 */
var judgeSquareSum = function(c) {
    a = 0
    b = Math.floor(Math.sqrt(c))
    while (a <= b) {
        p = a * a + b * b
        if (p < c)
            ++a
        else if (p > c)
            --b
        else
            return true
    }
    return false
};
