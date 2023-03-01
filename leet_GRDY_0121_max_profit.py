class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0
        lowest = prices[0]
        margin = 0
        for i in range(len(prices)):
            lowest = min(lowest, prices[i])
            margin = max(margin, prices[i] - lowest)
        return margin
