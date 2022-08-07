class Solution:
    def reverseWords(self, s: str) -> str:
        res = ' '.join(x[::-1] for x in s.split())
        return res
