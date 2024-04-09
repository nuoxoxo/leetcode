class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        res = 0
        for i in range(k + 1):
            res += min( tickets[i], tickets[ k ] )
        threshold = tickets[k] - 1
        for i in range(k + 1, len(tickets)):
            res += min( tickets[i], threshold )
        return res
