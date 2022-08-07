class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int x, i;

        if (nums.size() == 1)   return ;
        i = x = 0;
        while (i < (int) nums.size())
        {
            if (nums[i])
            {
                if (i != x)
                    swap(nums[i], nums[x]);
                ++ x;
            }
            ++ i;
        }
    }
};
