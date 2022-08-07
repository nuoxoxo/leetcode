class Solution:
    def freqAlphabets(self, s: str) -> str:
        size = len(s)
        res = ""
        i = 0
        while i < size:
            if i + 2 < size:
                if s[i + 2] == '#':
                    res += chr(int(s[i:i + 2]) - 1 + ord('a'))
                    i += 3
                    continue
            res += chr(int(s[i]) - 1 + ord('a'))
            i += 1
        return res
