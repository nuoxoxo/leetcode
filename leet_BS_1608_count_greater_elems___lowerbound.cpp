class Solution {
public:
    int specialArray(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int len = (int) nums.size();
        int k = -1;
        while (++k < len + 1)
        {
            int diff = nums.end() - std::lower_bound(nums.begin(), nums.end(), k);
            if (diff == k)
                return k;
        }
        return -1; 
    }
};
