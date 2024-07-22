class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]: 
        return [_[1] for _ in sorted([(h, n) for n, h in zip(names, heights)], reverse=True)]
