class Solution:
    def fib(self, n: int) -> int:
        return [
            self.Tabulation_1,
            self.Tabulation_2,
            # self.recurse, # TLE
        ][0](n)

    def recurse(self, n: int) -> int:
        if n < 2: return n
        return self.recurse(n-1) + self.recurse(n-2)

    def Tabulation_2(self, n: int) -> int:
        tbn = [0, 1]
        if n < 2:
            return tbn[n]
        for _ in range(2, n + 1):
            tbn.append(tbn[-2] + tbn[-1])
        return tbn[n]

    def Tabulation_1(self, n: int) -> int:
        if n < 2:
            return n
        tbn = [0] * (n + 1)
        tbn[1] = 1
        for i in range(2, n + 1):
            tbn[i] = tbn[i - 2] + tbn[i - 1]
        return tbn[n]
