class Solution:
    def minEnd(self, n: int, x: int) -> int:
        """

            (1)
        x = 4 -> 100
        n = 3
        x1 = 100
        x2 = 101
        x3 = 110 -> 6

            (2)
        x = 7 -> 111
        n = 2
             v
        x1 = 0111
        x2 = 1111 -> 15
        """
        n -= 1 
        N = [*bin(n)[2:]]
        Xreversed = [*bin(x)[2:][::-1]]
        # print(N, Xreversed)
        res = []
        for c in Xreversed:
            if c == '0':
                if N:
                    res.append(N.pop())
                else:
                    res.append('0')
            else:
                res.append('1')
        while N:
            res.append(N.pop())
        return int(''.join(res[::-1]), 2)

