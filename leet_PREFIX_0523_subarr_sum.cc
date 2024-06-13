class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        int running = 0;
        int mod = 0;
        set<int> seen;
        for (int n : nums)
        {
            running += n;
            int temp = running % k;
            if (seen.find(temp) != seen.end())
                return true;
            seen.insert(mod);
            mod = temp;
        }
        return false;
    }
};
