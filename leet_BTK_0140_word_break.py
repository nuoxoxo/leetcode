class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # S = set(wordDict)
        N = len(s)
        res = []
        # L -----> current index in s
        # curr --> current list of valid words
        def go(L: int, curr: List[str]):
            if L == N:
                nonlocal res
                res.append(' '.join(curr))
                return
            # for each left index, check all indexes to its right
            for R in range(L, N):
                word = s[L : R + 1]
                if word in wordDict:
                    curr.append(word)
                    go(R + 1, curr)
                    curr.pop()
        go(0, [])
        return res

