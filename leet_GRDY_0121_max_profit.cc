/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

///  fast

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int         lowest, margin, i;

        if (prices.size() == 1) return (0);
        lowest = prices[0];
        margin = i = 0;
        while (i < prices.size())
        {
            lowest = min(lowest, prices[i]);
            margin = max(margin, prices[i] - lowest);
            i++;
        }
        
        return (margin);
    }
};

///  slow original

/*

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int     profit, result, min, i;

        if (prices.size() == 1) return (0);
        min = prices[0] + 1;
        result = i = 0;
        while (i < prices.size() - 1)
        {
            if (prices[i] < min)
            {
                profit = *max_element(prices.begin() + i + 1, prices.end()) - prices[i];
                profit = profit > -1 ? profit : 0;
                result = profit > result ? profit : result;
                min = prices[i];
            }
            i++;
        }
        return (result);
    }
};

*/
