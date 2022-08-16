class Solution:
    def firstUniqChar(self, s: str) -> int:
        E = [0] * 26;
        a = ord('a')
        for c in s:
            E[ord(c) - a] += 1
        i = -1
        for c in s:
            i += 1
            if E[ord(c) - a] == 1:
                return i
        return -1

