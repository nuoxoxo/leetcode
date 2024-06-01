class Solution {
public:
    bool isArraySpecial(vector<int>& nums)
    {
        int N = nums.size();
        int i = -1;
        while (++i < N - 1)
        {
            if ((nums[i] & 1) == (nums[i + 1] & 1))
                return false;
        }
        return true;
    }
};
