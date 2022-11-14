class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        dq = [(s1, s2, s3)]
        visited = set((0, 0))
        while dq:
            t1, t2, t3 = dq.pop(0)
            if not t3:
                return not t1 and not t2
            if t1 and (t1[0] == t3[0]) and (len(t1) - 1, len(t2)) not in visited:
                dq.append((t1[1:], t2, t3[1:]))
                visited.add((len(t1) - 1, len(t2)))
            if t2 and (t2[0] == t3[0]) and (len(t1), len(t2) - 1) not in visited:
                dq.append((t1, t2[1:], t3[1:]))
                visited.add((len(t1), len(t2) - 1))
        return False
