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

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int         L, R, i, n;

        n = cost.size() + 1;
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = 0;
        i = 1;
        while (++i < n)
        {
            L = dp[i - 2] + cost[i - 2];
            R = dp[i - 1] + cost[i - 1];
            dp[i] = L < R ? L : R;
        }
        return dp[n - 1] ;
    }
};
