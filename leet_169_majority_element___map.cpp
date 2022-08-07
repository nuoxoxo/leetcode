class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        if (nums.size() == 1)   return nums[0] ;
        
        unordered_map<int, int> E;
        int record = -1e9;
        int res = nums[0];
        int i = -1;

        while (++i < nums.size())
        {
            E[nums[i]]++;
            if (record < E[nums[i]])
            {
                record = E[nums[i]];
                res = nums[i];
            }
        }
        return res ;
    }
};
