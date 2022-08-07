class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr)
    {
        int n = arr.size(), res, L, R;
        if (!n || n == 1)
            return 0;

        R = n - 1;
        while (R > 0 && arr[R - 1] <= arr[R])
            --R;
        res = R;
        L = -1;
        while (++L < n)
        {
            if (L >= R)
                break;
            if (L > 0 && arr[L - 1] > arr[L])
                break;
            while (R < n && arr[L] > arr[R])
                ++R;
            res = min(res, R - L - 1);
        }
        return res ;
    }
};
