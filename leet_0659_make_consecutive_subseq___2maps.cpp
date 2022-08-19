class Solution {
public:
    bool isPossible(vector<int>& nums)
    {
        unordered_map<int, int>     freq;
        unordered_map<int, int>     subs;

        for (int n : nums)
            freq[n]++;
        for (int n : nums)
        {
            if (!freq[n])
                continue ;
            freq[n]--;
            if (subs[n - 1] > 0)
            {
                subs[n - 1]--;
                subs[n]++;
            }
            else if (freq[n + 1] > 0 && freq[n + 2] > 0)
            {
                freq[n + 1]--;
                freq[n + 2]--;
                subs[n + 2]++;
            }
            else
                return false;
        }
        return true;
    }
};
