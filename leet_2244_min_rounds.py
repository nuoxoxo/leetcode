class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        E = {}
        for n in tasks:
            if n in E:
                E[n] += 1
            else:
                E[n] = 1
        res = 0
        for _, v in E.items():
            if v == 1:
                return -1
            if v == 2:
                res += 1
            elif v > 2:
                res += v // 3
                if v % 3 != 0:
                    res += 1
        return res
