class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1)
            return (true) ;
        int last_index = n - 1;
        int i = last_index ;
        while (-- i > -1)
        {
            if (i + nums[i] >= last_index)
                last_index = i;
        }
        return (!last_index) ;
    }
};
