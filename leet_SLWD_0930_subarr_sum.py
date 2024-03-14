class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        return [
            self.Sliding_window,
        ][0](nums, goal)

    def Sliding_window(self, nums: List[int], goal: int) -> int:
        N = len(nums)
        if N == 1: return 1 if nums[0] == goal else 0
        G = 0
        temp = 0
        l = 0
        # how many subarrays have : sum <= goal
        for r in range(N):
            temp += nums[r]
            while temp > goal:
                temp -= nums[l]
                l += 1
            G += r - l + 1
        if goal == 0:
            return G
        # how many subarrays have : sum <= goal - 1
        #   ---> at the end, res will be 
        #       size( subarrs where sum <= goal ) - size( subarrs where sum <= goal-1 )
        Gminus1 = 0
        temp = 0
        l = 0
        for r in range(N):
            temp += nums[r]
            while temp > goal - 1:
                temp -= nums[l]
                l += 1
            Gminus1 += r - l + 1
        return G - Gminus1
            
