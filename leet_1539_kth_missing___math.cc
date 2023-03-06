class Solution {
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        int i = 0;
        if (k - arr[0] + 1 < 1)
            return k;
        k -= arr[0] - 1;
        while (++i < (int) arr.size())
        {
            int diff = arr[i] - arr[i - 1] - 1;
            if (!diff)
                continue;
            if (k - diff < 1)
                break;
            k -= diff;
        }
        return arr[i - 1] + k;
    }
};
