class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        degrees = [0] * n
        for a, b in roads:
            degrees[a] += 1
            degrees[b] += 1
        # print(degrees)
        res = 0
        reverse = not True
        if reverse:
            degrees.sort(reverse=True)
            for idx, d in enumerate(degrees):
                res += (n - idx) * d
        else:
            degrees.sort()
            for idx, d in enumerate(degrees):
                res += (idx + 1) * d
        return res
