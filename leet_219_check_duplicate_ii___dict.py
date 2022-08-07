class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        E = dict()
        for i in range(len(nums)):
            n = nums[i]
            if n in E and abs(E[n] - i) <= k:
                    return True
            E[n] = i
        return False 
            
