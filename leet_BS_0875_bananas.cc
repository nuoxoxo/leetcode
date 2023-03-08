class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        sort(piles.begin(), piles.end());

        int M = piles[piles.size() - 1];
        int res = M;
        int R = M;
        int L = 1;
        while (L < R)
        {
            int mid = (R - L) / 2 + L;
            long long   hours = 0;

            for (int p: piles)           
            {
                hours += (p + mid - 1) / mid; // crucial line
            }
            if (hours > h)
                L = mid + 1;
            else
            {
                R = mid;
                res = min(res, mid);
            }
        }
        return res ;
    }
};
