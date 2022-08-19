class Solution:
    def countKDifference(self, n: List[int], k: int) -> int:
        r = 0
        for i in range(len(n)):
            for j in range(i + 1, len(n)):
                if abs(n[i] - n[j]) == k:
                    r += 1
        return r 
