class Solution {
public:
    bool isMonotonic(vector<int>& nums)
    {
        int     len = nums.size(), flag, i;

        if (len < 3)
            return true ;
        flag = 0;
        i = -1;
        while(++i < len - 1)
        {
            if (!flag && nums[i] < nums[i + 1])
                flag = 1;
            else if (!flag && nums[i] > nums[i + 1])
                flag = 2;
            else if (flag == 1 && nums[i] > nums[i + 1])
                return false;
            else if (flag == 2 && nums[i] < nums[i + 1])
                return false;
        }
        return true ;
    }
};
