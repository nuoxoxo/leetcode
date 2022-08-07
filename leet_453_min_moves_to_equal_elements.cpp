class Solution {
public:
    int minMoves(vector<int>& n)
    {
        int res, min;

        min = *min_element(n.begin(), n.end());
        res = 0;
        for (int cur: n)
        {
            res += cur - min;
        }
        return res;
    }
};
