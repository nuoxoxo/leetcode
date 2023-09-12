class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first)
    {
        vector<int> res = {first};
        int i = -1;
        while (++i < (int) encoded.size())
        {
            res.push_back(encoded[i] ^ res.back());
        }
        return res;
    }
};
