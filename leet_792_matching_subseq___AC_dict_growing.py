class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        seen = {}
        res = 0
        for w in words:
            if w in seen:
                res += seen[w]
                continue
            seen[w] = 0 # without this line - TLE
            i = 0
            for c in s:
                if c == w[i]:
                    i += 1
                if i == len(w):
                    res += 1
                    seen[w] = 1
                    break
        return res
