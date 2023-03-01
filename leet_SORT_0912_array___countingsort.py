
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        size = len(nums)
        mx = max(nums)
        mi = min(nums)
        rage = mx - mi + 1
        count = [0] * rage
        res = [0] * size
        for n in nums:
            count[n - mi] += 1
        print(count)
        for i in range(1, rage):
            count[i] += count[i - 1]
        print(count, '\n')
        for i in range(size - 1, -1, -1):
            n = nums[i] - mi
            res[count[n] - 1] = nums[i]
            count[n] -= 1;
            print('', res, '\n', count)
        return res

# testcase for counting sort demonstration
"""
[3,13,6,14,17,9,19,16,2,4]
"""
