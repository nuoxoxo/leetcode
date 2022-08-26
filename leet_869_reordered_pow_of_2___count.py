class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        def count_n(num: int) -> List[int]:
            r = [0] * 10
            while num > 0:
                r[num % 10] += 1
                num //= 10
            return r
        check = count_n(n)
        res, i = 0, 0
        while res < 10 ** 9 + 1:
            res = 2 ** i
            temp = count_n(res)
            if check == temp:
                return True
            i += 1
        return False
    
