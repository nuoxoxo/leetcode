class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        res = []
        D = {}
        for i in range(len(groupSizes)):
            L = groupSizes[i]
            if L not in D:
                D[L]  = []
            D[L].append(i)
            if len(D[L]) == L:
                res.append(D[L])
                D[L] = []
        return res
