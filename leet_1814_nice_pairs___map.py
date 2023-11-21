class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        D = defaultdict(int)
        for n in nums:
            original = n
            res = 0
            while n > 0:
                res = res * 10 + n % 10 # calc rev
                n //= 10
            D[original - res] += 1
        res = 0
        for _, v in D.items():
            print(_, v)
            res = (res + v * (v - 1) // 2) % int(1e9 + 7)
        return res

