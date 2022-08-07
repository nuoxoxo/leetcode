/**
 * @param {number[][]} coordinates
 * @return {boolean}
 */
var checkStraightLine = function(c) {
    n = c.length
    if (n == 2)
        return true
    dx = c[1][0] - c[0][0]
    dy = c[1][1] - c[0][1]
    slope = dx ? dy / dx : -1
    i = 1
    while (++i < n) {
        dx = c[i][0] - c[i - 1][0]
        dy = c[i][1] - c[i - 1][1]
        temp_slope = dx ? dy / dx : -1
        if (temp_slope != slope)
            return false
    }
    return true
};
