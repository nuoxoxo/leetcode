class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        check = Counter([int(_) for _ in str(n)])
        num, i = 0, 0
        while num < 1e9 + 1:
            num = 2 ** i
            temp = Counter([int(_) for _ in str(num)])
            if check == temp:
                return True
            i += 1
        return False
