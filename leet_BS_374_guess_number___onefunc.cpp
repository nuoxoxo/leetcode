/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n)
    {
        if (!guess(n))
            return n;
        int m = 1;
        while (m < n)
        {
            int mid = (n - m) / 2 + m;
            int x = guess(mid);
            if (!x)
                return mid;
            else if (x < 0)
                n = mid - 1;
            else
                m = mid + 1;
        }
        return m;
    }
};
