class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        q = []
        for c in s:
            if len(q) != 0 and c == q[-1][0]:
                if q[-1][1] == k - 1:
                    q.pop()
                else:
                    q[-1][1] += 1
            else:
                q.append([c, 1])
        res = ''
        while len(q) != 0:
            while q[0][1] > 0:
                res += q[0][0]
                q[0][1] -= 1
            q.pop(0)
        return res
