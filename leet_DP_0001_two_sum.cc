class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int>   mp;
        int             i;
        
        i = -1;
        while (++i < nums.size())
        {
            if ( mp.find(nums[i]) != mp.end() ) break;
            mp[target - nums[i]] = i;
        }
        return { mp[nums[i]], i };
    }
};
