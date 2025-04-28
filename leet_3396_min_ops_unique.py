class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        return [
            # Set_bruteforce, # not as efficient
            Two_dicts,
        ][0](nums)

def Two_dicts(nums: List[int]) -> int:
    counter = collections.Counter(nums)
    dpl = collections.defaultdict(int) # has duplicate
    for k,v in counter.items():
        if v > 1:
            dpl[k] = v - 1
    N = len(nums)
    res = 0
    for i in range(0,N,3):
        if sum(dpl.values()) == 0:
            break
        res += 1
        if i > N - 3:
            break
        a,b,c = nums[i:i+3]
        if dpl[a] != 0: dpl[a] -= 1
        if dpl[b] != 0: dpl[b] -= 1
        if dpl[c] != 0: dpl[c] -= 1
    return res

def Set_bruteforce(nums: List[int]) -> int:
    res = 0
    if len(set(nums)) == len(nums):
        return res
    while len(set(nums)) != len(nums):
        nums = nums[3:]
        res += 1
    return res

