class Solution:
    # unbounded knapsack problem
    #   - We have an `infinite` number of each coin
    #   - We freely choose an item as many times as we wish
    def change(self, amount: int, coins: List[int]) -> int:
        return [
            self.DP_Reverse_Recurrence_Relation,
            self.DP_Recurrence_Relation,
        ][ 1 ]( amount, coins )

    def DP_Reverse_Recurrence_Relation(self, amount: int, coins: List[int]) -> int:
        print('/RRR')
        M, C = amount, len(coins)
        dp = [[0 for _ in range(M + 1)] for _ in range(C)]
        for i in range(C):
            for m in range(M + 1):
                if m == 0:
                    dp[ i ][0] = 1
                    continue
                # before using the coin
                dp[ i ][ m ] = dp[ i - 1 ][ m ]
                # use the coin
                coin = m - coins[ i - 1 ]
                if coin > -1:
                    dp[ i ][ m ] += dp[ i ][ coin ]
        return dp[-1][-1]


    def DP_Recurrence_Relation(self, amount: int, coins: List[int]) -> int:

        print('/RR')
        M, C = amount, len(coins)
        dp = [[0 for _ in range(C + 1)] for _ in range(M + 1)]
        dp[0] = [1] * (C + 1)

        for i in range(C - 1, -1, -1):
        # for m in range(1, M + 1):
            for m in range(1, M + 1):
            # for i in range(C - 1, -1, -1):
                dp[ m ][ i ] = dp[ m ][ i + 1 ]
                coin = m - coins[i]
                if coin > -1:
                    dp[ m ][ i ] += dp[ coin ][i]
        return dp[ M ][0]
    
