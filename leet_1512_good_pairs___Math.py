class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        """
        Way 1: Counter
        """
        d = Counter(nums)

        """
        # Way 2: defaultdict(int)
        """

        # d = defaultdict(int)
        # for n in nums:
        #     d[n] += 1
        res = 0
        for _, n in enumerate(d):
            res += d[n] * (d[n] - 1) // 2
        return res

