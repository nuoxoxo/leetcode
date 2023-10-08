class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        temp = sorted(score, reverse=True)
        res = []
        for n in score:

            idx = temp.index(n)
            if idx == 0:
                res.append("Gold Medal")
            elif idx == 1:
                res.append("Silver Medal")
            elif idx == 2:
                res.append("Bronze Medal")
            else:
                res.append(str(idx + 1))

        return res
