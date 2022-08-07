class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size() ;
        int R = n - 1;
        int L = 0;
        while (L <= R)
        {
            int mp = (L + R) / 2;
            if (nums[mp] == target)
                return mp;
            if (nums[mp] > target)
                R = mp - 1;
            else
                L = mp + 1;
        }
        return -1;
    }
};
