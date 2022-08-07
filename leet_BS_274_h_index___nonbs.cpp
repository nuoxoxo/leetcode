class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end(), greater<int>());
        int i = -1, res;
        while (++i < (int) citations.size())
        {
            if (citations[i] >= i + 1)
                res = i + 1;
            else
                break;
        }
        return res;
    }
};
