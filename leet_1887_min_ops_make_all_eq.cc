class Solution {
public:
    int reductionOperations(vector<int>& nums)
    {
        // way 2
        sort(nums.begin(), nums.end());
        int res = 0;
        int dist = 0;
        int i = 0;
        while (++i < nums.size())
        {
            if (nums[i] ^ nums[i - 1])
                dist++;
            res += dist;
        }
        return res;

        // way 1

        /*
        sort(nums.begin(), nums.end());
        int res = 0;
        int len = (int) nums.size();
        int i = 0;
        while (++i < len)
        {
            if (nums[i] ^ nums[i - 1])
                res += len - i;
        }
        return res;
        */
    }
};
