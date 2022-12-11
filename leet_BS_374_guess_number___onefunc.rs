/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */

impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let mut m: i32 = 1;
        let mut nn: i32 = n;
        loop
        {
            let mut mid = (nn - m) / 2 + m;
            let mut x = guess(mid);
            if x == 0
            {
                return mid;
            }
            else if x < 0
            {
                nn = mid - 1;
            }
            else
            {
                m = mid + 1;
            }
        }
        m
    }
}
