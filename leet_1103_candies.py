class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0] * num_people
        idx = 0
        c = 1
        while candies:
            n = min(c, candies)
            candies -= n
            res[idx] += n
            idx = (idx + 1) % num_people
            c += 1
        return res
