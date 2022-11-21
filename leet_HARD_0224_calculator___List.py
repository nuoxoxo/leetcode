class Solution:
    def calculate(self, s: str) -> int:
        D = []
        size = len(s)
        sign = 1
        res = 0
        i = 0
        zero = ord('0')
        nine = ord('9')
        while i < size:
            c = ord(s[i])
            if zero <= c <= nine:
                tmp = 0
                # while zero <= ord(s[i]) <= nine and i < size:
                while i < size and zero <= ord(s[i]) <= nine:
                    tmp *= 10
                    tmp += ord(s[i]) - zero
                    i += 1
                res += sign * tmp
                i -= 1
            elif s[i] == '+':
                sign = 1
            elif s[i] == '-':
                sign = -1
            elif s[i] == '(':
                D.append(res)
                D.append(sign)
                sign = 1
                res = 0
            elif s[i] == ')':
                # assert s[i] == ')'
                res *= D.pop()
                res += D.pop()
            i += 1
        return res
