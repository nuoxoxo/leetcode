class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        return [k for k, v in sorted(collections.Counter(nums).items(), key=lambda x: (x[1], -x[0])) for _ in range(v)]
