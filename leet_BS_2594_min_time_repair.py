class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        L, R = 1, 10**20
        while L < R:
            mid = (L+R)//2
            canrepair = 0
            for rank in ranks:
                canrepair += int((mid / rank) ** .5)
            if canrepair < cars:
                L = mid + 1
            else:
                R = mid
        return L
