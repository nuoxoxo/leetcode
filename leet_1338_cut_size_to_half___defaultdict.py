class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        E = defaultdict(lambda: 0)
        for n in arr:
            E[n] += 1;
        V = []
        for _ in E.values():
            V.append(_)
        V.sort(reverse=True)
        la = len(arr)
        count = la
        res = 0
        for i in range(len(V)):
            if count <= la // 2:
                return res
            count -= V[i]
            res += 1
        return res
    
