class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        N = len(tokens)
        l, r = 0, N - 1
        res, pts = 0, 0
        while l <= r :
            if tokens[ l ] <= power:
                pts += 1
                res = max(res, pts)
                power -= tokens[ l ]
                l += 1
            elif pts > 0:
                pts -= 1
                power += tokens[ r ]
                r -= 1
            else:
                print('/both escaped')
                break
        return res
