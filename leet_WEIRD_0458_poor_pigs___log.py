class Solution:
    def poorPigs(self, buckets: int, mtd: int, mtt: int) -> int:
        return ceil(log(buckets) / log(mtt / mtd + 1))
