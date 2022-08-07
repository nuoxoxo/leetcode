class Solution:
    def canPlaceFlowers(self, FB: List[int], n: int) -> bool:
        size = len(FB)
        interval = i = 0

        if size == 1 and FB[0] == 0:
            return True
        while (i < size + 1):
            if i < size and FB[i] == 0:
                if i == 0 or i == size - 1:
                    interval += 1
                interval += 1
            else:
                n -= int((interval-1) / 2)
                interval = 0
                if n < 1:
                    return True
            i += 1
        return False 
"""
[0]
1
[0,1,0]
1
[1,0,0,0,1]
1
[1,0,0,0,1]
2
[1,0,0,0,1,0,0]
2
"""
