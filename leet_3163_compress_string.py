class Solution:
    def compressedString(self, word: str) -> str:
        prev = None
        res = ''
        count = 0
        for c in word:
            if c == prev:
                count += 1
                if count == 9:
                    count = 0
                    res += '9' + prev
            elif c != prev and prev:
                if count != 0:
                    res += str(count) + prev
                prev = c
                count = 1
            elif not prev:
                prev = c
                count += 1
        if count != 0:
            res += str(count) + prev
        return res
