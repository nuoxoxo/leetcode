class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        
        counter = collections.Counter(arr)
        a = []
        for key, v in counter.items():
            if v == 1:
                a.append(key)
        if k > len(a):
            return ""
        return a[k - 1]
            
