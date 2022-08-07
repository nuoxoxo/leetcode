/** 
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * var guess = function(num) {}
 */

/**
 * @param {number} n
 * @return {number}
 */

var guessNumber = function(n) {
    if (!guess(n))
        return n
    let m = 1
    while (m < n) {
        let mid = Math.floor((n - m) / 2) + m
        x = guess(mid)
        if (!x)
            return mid
        else if (x < 0)
            n = mid - 1
        else
            m = mid + 1
    }
    return m
};
