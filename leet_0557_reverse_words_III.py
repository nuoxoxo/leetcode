class Solution:
    def reverseWords(self, s: str) -> str:
        arr = s.split()
        for i in range(len(arr)):
            arr[i] = arr[i][::-1]
        # print(arr)
        return ' '.join(arr)
