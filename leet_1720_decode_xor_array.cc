class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first)
    {
        vector<int> res = {first};
        for (int n: encoded)
        {
            first ^= n;
            res.push_back(first);
        }
        return res;
    }
};
