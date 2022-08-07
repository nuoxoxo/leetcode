#* ******************************************** *#
#*                                              *#
#*              \\             /`/``            *#
#*              ~\o o_       0 0\               *#
#*              / \__)      (u  ); _  _         *#
#*       / \/ \/  /           \  \/ \/ \        *#
#*      /(   . . )            (         )\      *#
#*     /  \_____/              \_______/  \     *#
#*         []  []               [[] [[]    *.   *#
#*         []] []]              [[] [[]         *#
#*                                              *#
#* ************************************ nuo *** *#

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        
        n = len(cost)
        
        dp = [0] * (n + 1)
        # dp = defaultdict(lambda: 0) # defaultdict is faster
        
        i = 2
        while i <= n:
            L = dp[i - 2] + cost[i - 2];
            R = dp[i - 1] + cost[i - 1];
            dp[i] = L if L < R else R
            i += 1
        # print(dp)
        return dp[n]
