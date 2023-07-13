class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int>   s;
        int             i;

        i = -1;
        while (++i < nums.size())
        {
            int n = nums[i];
            if (s.find(n) != s.end() && abs(s[n] - i) <= k)
                return true ;
            s[n] = i;
        }
        return false ;
    }
};
