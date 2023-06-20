class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k)
    {
        if (!k)
            return nums;
        int window = 1 + k * 2;
        int len = nums.size();
        if (window > len)
            return (vector<int>(len, -1));
        vector<int> res(len, -1);
        int l = 0;
        int r = -1;
        long long tt = 0, avg = 0;
        while (++r < len)
        {
            tt += nums[r];
            if (r - l + 1 ^ window)
                continue ;
            avg = tt / window;
            res[r - k] = avg;
            tt -= nums[l];
            ++l;
        }
        return res;
    }
};
