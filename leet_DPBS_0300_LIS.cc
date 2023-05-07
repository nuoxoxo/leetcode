class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int>     temp;
        int             L, R, mid, len;

        for (int n: nums)
        {
            len = (int) temp.size();
            if (! len || n > temp[len - 1])
            {
                temp.push_back(n);
                // printer(temp);
            }
            else
            {
                L = 0;
                R = len - 1;
                while (L < R)
                {
                    mid = (R - L) / 2 + L;
                    if (temp[mid] < n)
                        L = mid + 1;
                    else
                        R = mid;
                }
                temp[R] = n;
            }
        }
        return ((int) temp.size());
    }

    void    printer(vector<int> temp)
    {
        int     i = -1;
        while (++i < (int) temp.size())
            cout << temp[i] << ' ';
        cout << endl;
    }
};
