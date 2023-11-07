class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        time = [(d + s - 1) // s for d, s in zip(dist, speed)]
        time.sort()
        res = 0
        for t in time:
            if res == t:
                break
            res += 1
        return res
