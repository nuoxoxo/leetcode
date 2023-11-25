class Solution {
public:
    int maxFrequency(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int res = -1;
        int len = (int) nums.size();
        vector<long long>   sums(len, 0); // prefix sum array
        sums[0] = nums[0]; // prefix begins
        int i = 0;
        while (++i < len)
            sums[i] = sums[i - 1] + nums[i]; // just like dp
        i = -1;
        while (++i < len)
            res = max(res, BS(sums, nums, i, k));
        return res;
    }

    int BS(vector<long long> & sums, vector<int> & nums, int idx, int k)
    {
        long long res = -1;
        long long l = 0;
        long long r = idx;
        while (l <= r)
        {
            long long mid = (r - l) / 2 + l;
            long long window_size = idx - mid + 1;
            long long sum_to_reach = window_size * nums[idx];
            long long sum_reachable = sums[idx];
            if (mid)
                sum_reachable -= sums[mid - 1];
            sum_reachable += k;
            if (sum_reachable < sum_to_reach) // can't reach, shrink from left
            {
                l = mid + 1;
            }
            else // ?
            {
                res = window_size;
                r = mid - 1;
            }
        }
        return res;
    }
};
