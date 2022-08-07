class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) == len(t):
            E = defaultdict(lambda: 0)
            for i in range(len(s)):
                E[s[i]] += 1
                E[t[i]] -= 1
            for e in E:
                if E[e] != 0:
                    return False
            return True
        return False
