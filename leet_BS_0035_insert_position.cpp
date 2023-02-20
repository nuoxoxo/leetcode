class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int R = nums.size() - 1, L = 0, mid;

        while (L <= R)
        {
            mid = (R - L) / 2 + L;
            if (nums[mid] < target)
                L = mid + 1;
            if (nums[mid] > target)
                R = mid - 1;
            if (nums[mid] == target)
                return mid;
        }
        return L;
    }
};
