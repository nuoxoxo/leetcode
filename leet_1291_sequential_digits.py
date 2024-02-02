class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        return [
            self.Enumeration,
            # self.Bruteforce_TLE,
        ][ random.randint(0, 0) ]( low, high )

    def Enumeration(self, low: int, high: int) -> List[int]:
        res = []
        for n in range(2, 11):
            for i in range(1, 11 - n):
                num = 0
                for j in range(n):
                    num = num * 10 + i + j
                if num in range(low, high + 1):
                    res.append(num)
        return res

    def Bruteforce_TLE(self, low: int, high: int) -> List[int]:
        def isSD(num: int) -> bool:
            s = str(num)
            for i in range(len(s) - 1):
                if int(s[i + 1]) - int(s[i]) != 1:
                    return False
            return True
        res = []
        for n in range(low, high + 1):
            if isSD(n):
                res.append(n)
        return res
