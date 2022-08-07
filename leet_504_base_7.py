class Solution:
    def convertToBase7(self, num: int) -> str:
        if num is 0:
            return "0"
        sign = False
        s = ""
        if num < 0:
            sign = True
            num = -num
        while num:
            s += str(num % 7)
            num //= 7
        return '-' + s[::-1] if sign else s[::-1]
