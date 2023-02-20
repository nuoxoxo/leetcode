class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int R = n - 1;
        int L = 0;
        if (target == nums[L])
            return L ;
        if (target == nums[R])
            return R ;
        while (L < R)
        {
            int mid = (R - L) / 2 + L;
            if (target == nums[mid])
                return mid ;
            if (nums[0] < nums[mid])
            {
                if (nums[0] < target && target < nums[mid])
                    R = mid;
                else
                    L = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target < nums[n - 1])
                    L = mid + 1;
                else
                    R = mid;
            }
        }
        return -1 ;
    }
};
