class NumberContainers:

    def __init__(self):
        self.indices = collections.defaultdict(sortedcontainers.SortedList) # n:(0,1,3,4,42,...)
        self.idx2num = {} # i:n, j:n2, ...

    def change(self, index: int, number: int) -> None:
        # index not taken --> set idx to num, add idx to num's indices
        # already taken ----> del idx from num's indices, set new idx
        if index in self.idx2num:
            # print(index,number,self.indices,self.idx2num)
            self.indices[self.idx2num[index]].remove(index)
        self.idx2num[index] = number
        self.indices[number].add(index)

    def find(self, number: int) -> int:
        if not self.indices[number]:
            return -1
        return self.indices[number][0]


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)
