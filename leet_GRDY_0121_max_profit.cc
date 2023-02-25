class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() < 2)
            return 0;
        int lowest = prices[0];
        int margin = 0;
        int i = 0;
        while (++i < prices.size())
        {
            lowest = lowest > prices[i] ? lowest : prices[i];
            margin = margin < prices[i] - lowest ? margin : prices[i] - lowest;
        }
        return margin;
    }
};
