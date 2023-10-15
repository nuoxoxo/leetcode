/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int len = mountainArr.length();
        int l = 1;
        int r = len - 2;
        int mid = (r - l) / 2 + l;
        int peak = mid;
        while (l <= r)
        {
            mid = (r - l) / 2 + l;
            int L = mountainArr.get(mid + 1);
            int R = mountainArr.get(mid - 1);
            int M = mountainArr.get(mid);
            if (L < M < R)
                l = mid + 1;
            else if (L > M > R)
                r = mid - 1;
            else
                break ;
        }
        peak = mid;
        l = 0;
        r = peak;
        while (l <= r)
        {
            mid = (r - l) / 2 + l;
            int M = mountainArr.get(mid);
            if (M == target)
                return mid;
            if (M < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        l = peak;
        r = len - 1;
        while (l <= r)
        {
            mid = (r - l) / 2 + l;
            int M = mountainArr.get(mid);
            if (M == target)
                return mid;
            if (M > target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};
