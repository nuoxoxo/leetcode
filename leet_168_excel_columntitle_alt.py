class Solution:
    def convertToTitle(self, c: int) -> str:
        s = ""
        while c:
            c -= 1
            s += chr(65 + c % 26)
            c //= 26
        
        return s[::-1]
