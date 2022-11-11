class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int     len = (int) nums.size();

        if (len < 2)
            return len;

        set<int>    s(nums.begin(), nums.end());

        nums.clear();
        nums.resize(s.size());
        copy(s.begin(), s.end(), nums.begin());
        return (int) nums.size();
    }
};
