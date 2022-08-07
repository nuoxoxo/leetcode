
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        from collections import defaultdict
        E = defaultdict(lambda: 0)
        for n, f, t in trips:
            print(n,f,t)
            for i in range(f, t):
                E[i] += n
        if capacity < max(E.values()):
            return False
        return True
