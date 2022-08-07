class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        a = []
        for i in range(n):
            a.append('a')
            k -= 1
        for i in range(n - 1, -1, -1):
            if k > 25:
                a[i] = 'z'
                k -= 25
            else:
                a[i] = chr(ord(a[i]) + k)
                break
        return "".join(str(c) for c in a)
