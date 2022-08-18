class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        E = dict()
        for n in arr:
            if n not in E:
                E[n] = 1
            else:
                E[n] += 1;
        V = []
        for _ in E.values():
            V.append(_)
        V.sort(reverse=True)
        la = len(arr)
        count = la
        res = 0
        for n in V:
            if count <= la // 2:
                return res
            count -= n
            res += 1
        return res
