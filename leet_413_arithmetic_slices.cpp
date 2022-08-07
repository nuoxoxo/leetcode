class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int len = nums.size();
        if (len < 3)
            return 0 ;

        int i = -1, j, res = 0, dif;
        while (++i < len - 2)
        {
            dif = nums[i + 1] - nums[i];
            j = i + 1 ;
            while (++j < len)
            {
                if (nums[j] - nums[j - 1] ^ dif)
                    break ;
                else
                    ++res ;
            }
        }
        return res ;
    }
};
