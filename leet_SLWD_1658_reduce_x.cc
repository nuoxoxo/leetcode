class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int tt = 0;
        for (int n: nums)
            tt += n;
        int len = (int) nums.size();
        int window = -1;
        int R = -1;
        int L = 0;
        int curr = 0;
        while (++R < len)
        {
            curr += nums[R];
            while (curr > tt - x && L <= R)
                curr -= nums[L++];
            if (curr == tt - x)
                window = max(window, R - L + 1);
        }
        return window == -1 ? -1 : len - window;
    }
};

