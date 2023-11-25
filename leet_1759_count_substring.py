class Solution:
    def countHomogenous(self, s: str) -> int:
        MD = int(1e9 + 7)
        res = 0
        dis = 1
        c = s[0]
        for i in range(1, len(s)):
            if c == s[i]:
                dis += 1
            else:
                res += ((dis * (dis + 1)) // 2) % MD
                dis = 1
                c = s[i]
        res += ((dis * (dis + 1)) // 2) % MD
        return res

