class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        return [
            self.Solution_counting,
            self.Solution_binary_search\
        ][ random.randint(0,1) ]( nums, target )

    def Solution_binary_search(self, nums, target):
        print('/Solution_binary_search')
        size = len(nums)
        Left = None
        l, r = 0, size - 1
        while l <= r:
            mid = (r - l) // 2 + l
            if nums[mid] == target:
                if mid > 0 and nums[mid - 1] == target:
                    r = mid - 1
                else:
                    Left = mid
                    break
            elif nums[mid] > target:
                r = mid - 1
            else:
                l = mid + 1
        if Left == None:
            return False
        length = 0
        while Left < size and nums[Left] == target:
            Left += 1
            length += 1
        return length > size / 2

    def Solution_counting(self, nums, target):
        print('/Solution_counting')
        D = defaultdict(int)
        for n in nums:
            D[n] += 1
        for n, v in D.items():
            if v > len(nums) // 2 and target == n:
                return True
            elif v > len(nums)//2:
                return False
        return False
