class Solution:
    def addBinary(self, a: str, b: str) -> str:
        la = len(a)
        lb = len(b)
        lmax = max(la, lb)
        diff = abs(la - lb)
        E = ''
        s = '0' * diff
        if la != lmax:
            a = s + a
        if lb != lmax:
            b = s + b
        # print(a, b, len(a), len(b), sep='\n')
        for i in range(lmax):
            E += str(int(a[i]) + int(b[i]))
        # print(E, E[::-1], sep='\n')
        carry = 0
        res = ''
        for c in E[::-1]:
            if c == '0':
                if carry == 0:
                    res += '0'
                else:
                    res += '1'
                    carry -= 1
            elif c == '1':
                if carry == 0:
                    res += '1'
                else:
                    res += '0'
            elif c == '2':
                if carry == 0:
                    carry += 1
                    res += '0'
                else:
                    res += '1'
        # print(res, carry)
        if carry != 0:
            for _ in range(carry):
                res += '1'
        return res[::-1]
                    
