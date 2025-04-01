class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        N = len(questions)
        DP = [0] * (N+1)
        for i in range(N-1,-1,-1):
            pt,pw = questions[i]
            nextpos = min(pw + i + 1,N)
            DP[i] = max(pt + DP[nextpos], DP[i+1])
        return DP[0]
