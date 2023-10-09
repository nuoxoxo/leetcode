class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int len = (int) nums.size();
        int l = 0;
        int r = len - 1;
        while (l <= r)
        {
            int mid = (r - l) / 2 + l;
            if (nums[mid] == target)
            {
                l = mid;
                r = mid;
                while (l > -1 && nums[l] == target)
                    --l;
                while (r < len && nums[r] == target)
                    ++r;
                return {l + 1, r - 1};
            }
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return {-1, -1};
    }
};
