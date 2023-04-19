class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        e = floor(math.sqrt(area))
        while e > 0:
            if area % e == 0:
                break
            e -= 1
        return [area // e, e]
        
