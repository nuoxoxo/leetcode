class Solution:
    def maxArea(self, height: List[int]) -> int:
        e = len(height) - 1
        s = 0
        res = 0
        while s < e:
            tmp = min(height[s], height[e]) * (e - s)
            res = max(res, tmp)
            if height[s] < height[e]:
                s += 1
            else:
                e -= 1
        return res
            
        
