class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        rr = [0] * n
        cc = [0] * n
        for t in trust:
            rr[t[0] - 1] += 1
            cc[t[1] - 1] += 1
        for i in range(n):
            if rr[i] == 0 and cc[i] == n - 1:
                return i + 1
        return -1 
