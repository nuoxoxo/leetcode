class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        most = max(candies)
        res = []
        for n in candies:
            if n + extraCandies < most:
                res.append(False)
            else:
                res.append(True)
        return res
