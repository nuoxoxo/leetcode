class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int len = (int) nums.size();
        int R = len - 1;
        int L = 0;
        while (L <= R)
        {
            int mid = (R - L) / 2 + L;
            if (nums[mid] == target)
            {
                L = R = mid;
                while (L > -1 && nums[L] == target)
                    --L;
                while (R < len && nums[R] == target)
                    ++R;
                return {L + 1, R - 1};
            }
            if (nums[mid] < target)
                L = mid + 1;
            else
                R = mid - 1;
        }
        return {-1, -1}; 
    }
};
