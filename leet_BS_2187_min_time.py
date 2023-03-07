class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        l = 0
        r = min(time) * totalTrips # math bound
        def ok(n):
            trips = 0
            for t in time:
                trips += n // t
            return trips >= totalTrips
        while l < r:
            mid = (l + r) // 2
            if ok(mid):
                r = mid
            else:
                l = mid + 1
        return l
