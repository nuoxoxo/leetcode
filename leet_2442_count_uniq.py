class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        return [
            # oneliner,
            using_set,
        ][0](nums)

def oneliner(nums: List[int]) -> int:
    return len(set([int(str(_)[::-1]) for _ in nums] + nums))

def using_set(nums: List[int]) -> int:
    def rev(num: int) -> int:
        return int(str(num)[::-1])
    alt = []
    for n in nums:
        alt.append(rev(n))
    return len(set(nums + alt))
