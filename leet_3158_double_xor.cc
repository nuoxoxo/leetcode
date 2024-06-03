class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums)
    {
        int res = 0;
        set<int> S;
        for (int n: nums)
        {
            if (S.find(n) != end(S))
                res ^= n;
            else
                S.insert(n);
        }
        return res;
    }
};
