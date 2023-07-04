class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        set<int>    E;
        int         i = -1;

        while (++i < nums.size())
        {
            if (find(E.begin(), E.end(), nums[i]) != E.end())
                E.erase(nums[i]);
            else
                E.insert(nums[i]);
        }
        return (*E.begin());
    }
};

