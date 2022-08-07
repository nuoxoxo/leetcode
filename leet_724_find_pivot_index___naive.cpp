class Solution {
public:
    int pivotIndex(vector<int>& n)
    {
        int s = std::accumulate(n.begin(), n.end(), 0);
        float cur = 0;
        int i = -1;

        while (++i < (int) n.size())
        {
            if (i)
                cur += n[i - 1];
            if (cur == (float) (s - n[i]) / 2)
                return i;
        }
        return -1;
    }
};
