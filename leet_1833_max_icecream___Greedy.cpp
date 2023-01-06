class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        int res = 0;
        int i = -1;
        sort(costs.begin(), costs.end());
        while (++i < costs.size())
        {
            if (costs[i] > coins)
                break ;
            ++res;
            coins -= costs[i];
        }
        return res;
    }
};
