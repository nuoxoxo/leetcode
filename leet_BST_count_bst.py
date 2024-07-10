class Solution:
    def numTrees(self, n: int) -> int:
        return [
            # DP,
            Nth_Catalan_number_divide_and_conquer,
        ][0](n)

def Nth_Catalan_number_divide_and_conquer(n:int) -> int:
    cached = [[False for _ in range(n)] for _ in range(n)]
    caching = [[None for _ in range(n)] for _ in range(n)]
    def catalan(N) -> int:
        if N < 2:
            return 1
        #  .  . . . . . . . . --> n = 9 ie. 0~8
        # [.][. . . . . . . .]
        #     ^ ^ ^ ^ ^ ^ ^ ^ --> n - Left - 1 = 9-0-1
        #  ^ ---> (for every) L-index
        res = 0
        for left in range(N):
            right = N - left - 1
            if not cached[left][right]:
                cached[left][right] = True
                caching[left][right] = catalan(left) * catalan(right)
            # L ways for left tree
            # R ways for right tree, ie. L*R ways in total
            res += caching[left][right]
        return res
    return catalan(n)

def DP(n: int) -> int:
    dp = [0 for _ in range(n + 1)]
    dp[0] = 1
    dp[1] = 1
    for right in range(2, n + 1):
        for left in range(right):
            print(left, right, dp)
            temp = dp[left] * dp[right - left - 1]
            dp[right] += temp
    return dp[n]
