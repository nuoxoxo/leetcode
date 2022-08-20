class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        i = 0
        for c in s:
            if c == ' ':
                k -= 1
                if k is 0:
                    break
            i += 1
        return s[:i]
