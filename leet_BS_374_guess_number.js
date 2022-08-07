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
    function recurse(a, b) {
        let mid = Math.floor((b - a) / 2) + a
        let g = guess(mid)
        switch (g) {
            case 0:     return mid
            case 1:     return recurse(mid + 1, b)
            case -1:    return recurse(a, mid - 1)
        }
    }
    return recurse(1, n)
};
