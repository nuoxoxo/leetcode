class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        D = defaultdict(lambda: 0)
        S = set()
        for n in arr:
            D[n] += 1
        for n in arr:
            S.add(D[n])
        return len(S) == len(D)
