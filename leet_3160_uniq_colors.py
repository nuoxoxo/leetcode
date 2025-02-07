class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        # IMPORTANT: we'll get TLE w/o using defaultdict 
        D = collections.defaultdict(int)
        colors = collections.defaultdict(int)
        # D = [0] * (limit + 1)
        # colors = {}
        zero = limit + 1
        res = []
        for x,y in queries:
            if colors[D[x]] != 0:
                colors[D[x]] -= 1
                if colors[D[x]] == 0:
                    zero += 1
            if colors[y] == 0:
                zero -= 1
            res.append(limit + 1 - zero)
            colors[y] += 1
            D[x] = y
        return res

