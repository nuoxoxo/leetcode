class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        temp = []
        for n in nums:
            size = len(temp)
            if size == 0 or n > temp[-1]:
                temp.append(n)
                # print(temp)
            else:
                L = 0
                R = size - 1
                while L < R:
                    mid = (R - L) // 2 + L
                    if temp[mid] < n:
                        L = mid + 1
                    else:
                        R = mid
                temp[R] = n
        return len(temp)
