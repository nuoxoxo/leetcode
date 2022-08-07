class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int             len, mid, i, j;

        len = nums.size();
        i = 0;
        j = len - 1;
        while (i <= j)
        {
            mid = (j - i) / 2 + i;
            if (nums[mid] < target)
                i = mid + 1;
            else if (nums[mid] > target)
                j = mid - 1;
            else
            {
                i = j = mid;
                while (i > -1 && nums[i] == target)
                    --i;
                while (j < len && nums[j] == target)
                    ++j;
                return {i + 1, j - 1};
            }
        }
        return {-1, -1};
    }
};
