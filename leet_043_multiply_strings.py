class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return '0'
        n1 = len(num1)
        n2 = len(num2)
        z = ord('0')
        prod = [0] * (n1 + n2)
        res = ''
        for i in range(n1 - 1, -1, -1):
            for j in range(n2 - 1, -1, -1):
                a = ord(num1[i]) - z
                b = ord(num2[j]) - z
                p = a * b + prod[i + j + 1]
                prod[i + j] = p // 10 + prod[i + j]
                prod[i + j + 1] = p % 10
        i = 0
        while prod[i] == 0:
            i += 1
        while i < n1 + n2:
            res += str(prod[i])
            i += 1
        return res
