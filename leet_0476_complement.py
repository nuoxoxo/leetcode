class Solution:
    def findComplement(self, num: int) -> int:
        s = bin(num)[2:]
        r = ''
        for c in s:
            r += '1' if c == '0' else '0'
        # print(s, r)
        return int(r, 2)
