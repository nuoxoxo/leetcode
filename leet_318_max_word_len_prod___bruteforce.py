class Solution:
    def maxProduct(self, words: List[str]) -> int:
        def cmp(a: List[int], b: List[int]) -> bool:
            for i in range(26):
                if a[i] > 0 and b[i] > 0:
                    return False
            return True
        res = 0
        n = len(words)
        count = [[0] * 26 for _ in range(n)]
        for i in range(n):
            for c in words[i]:
                count[i][ord(c) - 97] += 1
            for j in range(i):
                if cmp(count[i], count[j]):
                    res = max(len(words[i]) * len(words[j]), res)
        return res
