class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = int(1e9+7)
        indexes = []
        sums = [0] * len(arr)
        for i in range(len(arr)):
            print('/bef.',end=' ')
            for index in indexes:print(arr[index],end=' ')
            while indexes and arr[i] < arr[ indexes[-1] ]:
                indexes.pop()
            print()
            print('/aft.',end=' ')
            for index in indexes:print(arr[index],end=' ')
            print()
            if not indexes:
                idx = -1
                temp = 0
            else:
                idx = indexes[-1]
                temp = sums[idx]
            sums[i] = temp + (i - idx) * arr[i]
            sums[i] %= MOD
            indexes.append( i )
        return sum(sums) % MOD
