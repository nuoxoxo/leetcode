/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
    if (guess(n) == 0) {
        return n
    }
    m := 1
    for m < n {
        mid := (n - m) / 2 + m;
        x := guess(mid)
        if (x == 0) {
            return mid
        } else if x < 0 {x
            n = mid - 1
        } else {
            m = mid + 1
        }
    }
    return m
}
