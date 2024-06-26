class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        res, l, r = 0, 0, len(people) - 1
        people.sort()
        while l <= r:
            if people[l] + people[r] <= limit:
                l += 1
            r -= 1
            res += 1
        return res
