class Solution:
    def poorPigs(self, buckets: int, mtd: int, mtt: int) -> int:
        pigs = 0
        while pow((mtt // mtd + 1), pigs) < buckets:
            pigs += 1
        return pigs
