"""
[2,1,3,4]

010
001
011
100

100 array XOR'd
001 k
---
101 there are two 1's

"""

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        res = 0
        target = 0
        for n in nums:
            target ^= n
        target ^= k
        return [
            Using_bit_count,
            Using_bin_count_1,
        ][random.randint(0, 1)](target)

def Using_bit_count(target: int) -> int:
    return target.bit_count()

def Using_bin_count_1(target: int) -> int:
    return bin(target).count('1')

