class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        freq = defaultdict(lambda: 0)
        subs = defaultdict(lambda: 0)
        for n in nums:
            freq[n] += 1
        for n in nums:
            if freq[n] == 0:
                continue
            freq[n] -= 1
            if subs[n - 1] > 0:
                subs[n - 1] -= 1
                subs[n] += 1
            elif freq[n + 1] > 0 and freq[n + 2] > 0:
                freq[n + 1] -= 1
                freq[n + 2] -= 1
                subs[n + 2] += 1
            else:
                return False
        return True

