class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        E = [ (scores[i], ages[i]) for i in range(len(ages)) ]
        E.sort()
        # print(E)
        dp = [ e[0] for e in E ]
        for i in range(len(E)):
            score, age = E[i]
            for j in range(i):
                temp_s, temp_a = E[j]
                if age >= temp_a:
                    dp[i] = max(dp[i], score + dp[j])
        return max(dp)
