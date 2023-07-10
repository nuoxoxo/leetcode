class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return '0'
        len1 = len(num1)
        len2 = len(num2)
        zero = ord('0')
        p = [0] * (len1 + len2)
        res = ''
        for i in range(len1 - 1, -1, -1):
            for j in range(len2 - 1, -1, -1):

                # way 1
                L = ord(num1[i]) - zero
                R = ord(num2[j]) - zero
                temp = L * R + p[i + j + 1]
                p[i + j] = temp // 10 + p[i + j]
                p[i + j + 1] = temp % 10 

                # way 2
                """
                L = i + j
                R = i + j + 1
                tmp = (ord(num1[i]) - zero) * (ord(num2[j]) - zero) + p[R]
                p[L] = tmp // 10 + p[L]
                p[R] = tmp % 10
                """
        i = 0
        while p[i] == 0:
            i += 1
        while i < len1 + len2:
            res += str(p[i])
            i += 1
        return res
