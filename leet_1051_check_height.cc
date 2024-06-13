class Solution {
public:
    int heightChecker(vector<int>& heights)
    {
        vector<int> sorted = heights;
        sort(begin(sorted), end(sorted));
        int res = 0;
        int i = -1;
        while (++i < sorted.size())
            res += sorted[i] != heights[i];
        return res;
    }
};
