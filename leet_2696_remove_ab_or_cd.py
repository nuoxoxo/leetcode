class Solution:
    def minLength(self, s: str) -> int:
        Q = deque()
        res = 0
        for c in s:
            if c in 'BD' and Q and Q[-1] == chr(ord(c) - 1):
                res += 1
                Q.pop()
            else:
                Q.append(c)
        return len(s) - res * 2
