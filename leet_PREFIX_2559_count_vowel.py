class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        def ok(s):
            return s[0] in 'aeiou' and s[-1] in 'aeiou'
        # prefix sum
        pfs = [0]
        for w in words: pfs.append(ok(w) + pfs[-1])
        res = [pfs[r + 1] - pfs[l] for l,r in queries]
        return res
