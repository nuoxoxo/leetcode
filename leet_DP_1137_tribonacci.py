class Solution:
    def tribonacci(self, n: int) -> int:
        return [
            self.Tabulation_1,
            self.Tabulation_2,
            # self.recurse, # TLE
        ][0](n)

    def recurse(self, n: int) -> int:
        if n < 2: return n
        if n == 2:return 1
        return self.recurse(n-1) + self.recurse(n-2) + self.recurse(n-3)

    def Tabulation_2(self, n: int) -> int:
        tbn = [0, 1, 1]
        if n < 3:
            return tbn[n]
        for _ in range(3, n + 1):
            tbn.append(tbn[-3] + tbn[-2] + tbn[-1])
        return tbn[n]

    def Tabulation_1(self, n: int) -> int:
        if n == 0:
            return n
        if n < 3:
            return 1
        tbn = [0] * (n + 1)
        tbn[1] = tbn[2] = 1
        for i in range(3, n + 1):
            tbn[i] = tbn[i - 3] + tbn[i - 2] + tbn[i - 1]
        return tbn[n]
