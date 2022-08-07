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
        return recurse(1, n);
    }

    int recurse(int L, int R)
    {
        int mid = (R - L) / 2 + L;
        if (guess(mid) > 0)
            return recurse(mid + 1, R);
        if (guess(mid) < 0)
            return recurse(L, mid - 1);
        return mid;
    }
};
