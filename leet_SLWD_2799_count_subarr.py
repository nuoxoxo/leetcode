class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        return [
            # direct_solution,
            using_dict,
        ][0](nums)

def direct_solution(nums: List[int]) -> int:
    UN = len(set(nums))
    N = len(nums)
    res = 0
    for L in range(N):
        S = set()
        for R in range(L, N):
            S.add(nums[R])
            if len(S) == UN:
                res += 1
    return res

def using_dict(nums: List[int]) -> int:
    N = len(nums)
    L, R = 0,0
    UN = len(set(nums))
    D = collections.defaultdict(int)
    res = 0
    while L < N:
        # print('L/R -',L,R)
        D[nums[L]] += 1
        while len(D) == UN:
            D[nums[R]] -= 1
            if D[nums[R]] == 0:
                D.pop(nums[R])
            R += 1

            # we count every subarr that has:
            #   L as left-bound
            #   R:N+1 as right-bound
            res += N - L

        L += 1
    return res

