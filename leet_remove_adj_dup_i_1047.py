class Solution:
    def removeDuplicates(self, s: str) -> str:
        q = []
        for c in s:
            if len(q) != 0 and c == q[-1]:
                q.pop()
            else:
                q.append(c)
        return ''.join(q)
