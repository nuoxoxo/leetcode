class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        set<int>    S(nums.begin(), nums.end());

        if (!nums.size())       return (0);
        if (nums.size() == 1)   return (1);
        nums.clear();
        nums.resize(S.size());
        copy(S.begin(), S.end(), nums.begin());

        return (nums.size());
    }
};
