class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int R = -1, L = 0, N = nums.size();
        unordered_map<int, int> D;
        int res = -1;
        while (++R < N)
        {
            D[nums[R]]++;
            while (D[nums[R]] > k)
            {
                D[nums[L]]--;
                L++;
            }
            res = max(res, R - L + 1);
        }
        return res;
    }
};
