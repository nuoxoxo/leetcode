class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        map<int, int>   D;
        int res = 0;
        for (int n: nums)
        {
            D[n] += 1;
        }
        map<int, int>::iterator it = D.begin();
        while (it != D.end())
        {
            if (it->second > 1)
                res += it->second * (it->second - 1) / 2;
            ++it;
        }
        return res;
    }
};
