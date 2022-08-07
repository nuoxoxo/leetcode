class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        a = list(s)
        c1 = a[0]
        c2 = a[3]
        n1 = int(a[1])
        n2 = int(a[-1])
        rest = []
        while ord(c1) < ord(c2) + 1:
            i = n1
            while i < n2 + 1:
                temp = c1 + str(i)
                rest.append(temp)
                i += 1
            c1 = chr(ord(c1) + 1)
        return rest
