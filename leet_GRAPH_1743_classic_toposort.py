class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        D = defaultdict(list)
        idg = defaultdict(int)
        for a, b in adjacentPairs:
            D[a].append(b)
            D[b].append(a)
            idg[b] += 1
        size = len(adjacentPairs) + 1
        res = []
        seen = set()
        # look for the beginning
        curr = -1e9
        for k, v in idg.items():# enumerate(idg):
            if v == 1:
                curr = k
                break
        # print(D, idg, node)
        for i in range(size):
            seen.add(curr)
            res.append(curr)
            idg[a] += 1
            for n in D[curr]:
                idg[n] -= 1
                if n not in seen and idg[n] < 2:
                    curr = n
                    break
        return res


