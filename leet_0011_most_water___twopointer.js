/**
 * @param {number[]} height
 * @return {number}
 */

var maxArea = function(height) {
    let R = height.length - 1
    let L, tmp, res
    res = L = 0
    while (L < R) {
        tmp = height[L] < height[R] ? height[L] : height[R]
        tmp = tmp * (R - L)
        res = tmp > res ? tmp : res
        if (height[L] < height[R])
            ++L
        else
            --R
    }
    return res
};
