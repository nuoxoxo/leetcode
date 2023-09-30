class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        D = []
        for i in range(len(prices)):
            while D and not prices[D[-1]] < prices[i]:
                idx = D.pop()
                prices[idx] -= prices[i]
            D.append(i)
        return prices
