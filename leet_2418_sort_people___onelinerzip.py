class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]: 
        return [_[0] for _ in \
            reversed(sorted(
                list(zip(names, heights)),
                key=lambda x: x[1])
            )]
