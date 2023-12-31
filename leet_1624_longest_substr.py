class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        D = defaultdict(list)
        for i, c in enumerate(s):
            D[c].append(i)
        res = -1
        for arr in D.values():
            if len(arr) > 1:
                res = max(res, arr[-1] - arr[0] - 1)
        return res
