class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        D = defaultdict(list)
        idg = defaultdict(int)
        for a, b in adjacentPairs:
            D[a].append(b)
            D[b].append(a)
            idg[a] += 1
            idg[b] += 1
        res = []
        isFound = False
        # look for the beginning
        dq = []
        head, tail = 42, 42
        for k, v in idg.items(): # enumerate(idg): ### wrong fn
            if v == 1:
                if isFound:
                    tail = k
                    break
                else:
                    isFound = True
                    head = k
                    dq.append(head)
        while dq:
            node = dq.pop(0)
            res.append(node)
            for n in D[node]:
                idg[n] -= 1
                if idg[n] == 1:
                    dq.append(n)
        res.append(tail)
        return res

