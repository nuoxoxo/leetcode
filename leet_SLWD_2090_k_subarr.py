class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        if k == 0:
            return nums
        window = 1 + k * 2
        size = len(nums)
        if window > size:
            return [-1] * size
        res = [-1] * size
        l = 0
        r = -1
        tt = 0
        avg = 0
        while r < size - 1:
            
            # marching eastward (1/2)
            r += 1
            tt += nums[r]

            # if we have a window width
            if r - l + 1 != window:
                continue
            avg = tt // window
            res[r - k] = avg

            # marching eastward (2/2): cut the tail
            tt -= nums[l]
            l += 1
        return res
