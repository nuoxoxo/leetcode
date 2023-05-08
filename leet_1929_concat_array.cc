class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums)
    {
        int         i = 3;
        vector<int> res;

        while (--i)
        {
            for (int n : nums)
                res.push_back(n);
        }
        return res;
    }
};
