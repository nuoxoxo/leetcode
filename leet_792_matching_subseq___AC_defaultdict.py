class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        seen = defaultdict(lambda: 0)
        ls = len(s)
        res = 0
        for w in words:
            seen[w] += 1
        words = list(dict.fromkeys(words))
        for w in words:
            i = 0
            j = 0
            lw = len(w)
            while i < ls and j < lw:
                if s[i] == w[j]:
                    j += 1
                i += 1
            if j == lw:
                res += seen[w]
        return res
