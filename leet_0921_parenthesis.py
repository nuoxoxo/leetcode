class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        D = collections.deque()
        for c in s:
            if c == ')' and D and D[0] == '(':
                D.popleft()
            else:
                D.appendleft(c)
        return len(D)
                
