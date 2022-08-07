class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mx)
    {
        vector<vector<int>> res;
        int r, c;

        c = -1;
        while (++c < (int) mx[0].size())
        {
            vector<int> tmp;

            r = -1;
            while (++r < (int) mx.size())
                tmp.push_back(mx[r][c]);
            res.push_back(tmp);
        }
        return res;
    }
};
