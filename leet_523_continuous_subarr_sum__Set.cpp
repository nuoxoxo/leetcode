class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        set<int>    s;
        int sum = 0, mod = 0;

        for (int n: nums)
        {
            sum += n;
            int temp = sum % k;

            if (s.find(temp) != s.end())
                return true;
            s.insert(mod);
            mod = temp;
            
        }
        return false;
    }
};
