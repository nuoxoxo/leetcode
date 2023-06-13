class Solution {
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        map<string, int>    dict;
        vector<string>      cols;
        int len = (int) grid.size();
        int res = 0;

        cols.resize(len);
        for (vector<int> nums: grid)
        {
            string  s;
            string  tmp;
            int     i = -1;

            while (++i < len)
            {
                tmp = to_string(nums[i]);
                s += ' ' + tmp;
                cols[i] += ' ' + tmp;
            }
            ++dict[s];
        }
        for (string c: cols)
            res += dict[c];
        return res;
    }
};
