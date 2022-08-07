class Solution {
public:
    int maxScore(vector<int>& p, int k)
    {
        int best = std::accumulate(p.begin(), p.begin() + k, 0);
        int n = p.size();
        int temp = best;
        int i = 0;
        while (++i < k + 1)
        {
            temp += p[n - i];
            temp -= p[k - i];
            best = max(best, temp);
        }
        return best;
    }
};
