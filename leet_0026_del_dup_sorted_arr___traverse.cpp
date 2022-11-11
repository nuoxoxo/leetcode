class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int     len = (int) nums.size();
        int     i, j;

        if (len < 2)
            return len;
        i = j = 0;
        while (++j < len)
        {
            if (nums[i] ^ nums[j])
            {
                nums[i + 1] = nums[j];
                ++i;
            }
        }
        ++i;
        nums = vector<int>(nums.begin(), nums.begin() + i);
        return i;
    }
};
