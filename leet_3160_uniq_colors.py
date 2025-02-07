class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        # IMPORTANT: we'll get TLE w/o using defaultdict 
        D = collections.defaultdict(int)
        colors = collections.defaultdict(int)
        # D = [0] * (limit + 1)
        # colors = {}
        curr = 0
        res = []
        for x,y in queries:
            oc = D[x]
            if colors[oc] > 0:
                colors[oc] -= 1
                if colors[oc] == 0:
                    curr -= 1
            if colors[y] == 0:
                curr += 1
            res.append(curr)
            colors[y] += 1
            D[x] = y
        return res

