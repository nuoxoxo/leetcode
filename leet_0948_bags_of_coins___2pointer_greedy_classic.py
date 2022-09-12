class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        cur = 0
        res = 0
        i = 0
        j = len(tokens) - 1
        while i < j + 1:
            if tokens[i] < power + 1:
                cur += 1
                res = max(res, cur)
                power -= tokens[i]
                i += 1
            elif cur > 0:
                cur -= 1
                power += tokens[j]
                j -= 1
            else:
                break
        return res
