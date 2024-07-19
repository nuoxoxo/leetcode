class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        # [1,1,0], k = 2
        #   -> [1,0,1] -> we can flip these 2
        #         ^ ^ 
        #   -> [0,0,1] -> or we can flip these
        #       ^ ^ 
        #   -> impossible bc. a 0- or 1-bit is left either way
        #
        # [0,0,0,1,0,1,1,0], k = 3
        #   -> [1,1,1,1,0,1,1,0] -> step1
        #       ^ ^ ^ 
        #   -> [1,1,1,1,1,0,0,0] -> step2
        #               ^ ^ ^
        #   then flip the final len-3 subarr
        #
        #       Strategy
        # once we can flip we flip, store the window flipped, swicth state and gain 1
        # once we meet the R-index of a window, dispose this window, swich the state
        #       Tool
        # a queue to store the window where flips happen.
        # a window is identified by the R-index of the window.
        N = len(nums)
        ENDS = deque()
        flipping = 0 # imagine if [0] is a 0, we have no choice but flipping it
        res = 0
        for i, curr in enumerate(nums):
            # once we meet an R-index of a marked subarr of len-k 
            # we pop ie. flip the subarr[ prevIndex : prevIndex + k ]
            if ENDS and ENDS[0] == i:
                flipping ^= 1
                ENDS.popleft()
            if flipping == curr:
                # flip next k bits
                flipping ^= 1
                ENDS.append(i + k)
                res += 1
        if len(ENDS) > 1:
            return -1
        if not ENDS or ENDS[0] == N:
            return res
        return -1
