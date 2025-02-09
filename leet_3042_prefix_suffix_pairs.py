class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        res = 0
        N = len(words)
        for l in range(N - 1):
            for r in range(l + 1, N):
                L,R = words[l],words[r]
                res += R.startswith(L) and R.endswith(L)
        return res # bruteforced
