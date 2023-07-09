class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        def isSD(num: int):
            n = num
            while n > 0:
                div = n % 10
                if div == 0 or num % div != 0:
                    return False
                n //= 10
            return True
        res = []
        for n in range(left, right + 1):
            if isSD(n):
                res.append(n)
        return res

