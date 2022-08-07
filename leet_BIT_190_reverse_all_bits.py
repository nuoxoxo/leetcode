class Solution:
    def reverseBits(self, n: int) -> int:
        s = "{:032b}".format(n)
        r = s[::-1]
        return eval('0b' + r)
