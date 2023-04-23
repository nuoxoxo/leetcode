// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n)
    {
        int res = n;
        int L = 1;
        int R = n;
        
        while (L <= R)
        {
            int mid = (R - L) / 2 + L;
            if (isBadVersion(mid))
            {
                res = mid;
                R = res - 1;
            }
            else
                L = mid + 1;
        }
        return res;
    }
};
