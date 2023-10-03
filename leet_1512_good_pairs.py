class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        def count(n: int) -> int:
            res = 0
            n -= 1
            while n > 0:
                res += n
                n -= 1
            return res

        """
        Way 1: Counter
        """
        # d = Counter(nums)

        """
        # Way 2: defaultdict(int)
        """

        d = defaultdict(int)
        for n in nums:
            d[n] += 1
        res = 0
        for _, n in enumerate(d):
            if d[n] > 1:
                res += count(d[n])
        return res

