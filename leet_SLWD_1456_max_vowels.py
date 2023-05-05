class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        v = 'aeiou'
        res = 0
        temp = 0
        l = 0
        for r, c in enumerate(s):
            if c in v:
                temp += 1
            if r - l == k:
                if s[l] in v:
                    temp -= 1
                l += 1
            res = max(res, temp)
        return res
