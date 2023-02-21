class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int r = 0;
        for (int n: nums)
            r ^= n;
        return r;
    }
};
