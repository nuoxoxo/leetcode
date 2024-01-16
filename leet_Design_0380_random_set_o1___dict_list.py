class RandomizedSet:

    def __init__(self):
        self.getIndexByVal = {}
        self.arr = []

    def insert(self, val: int) -> bool:
        if val in self.arr:
            return False
        self.arr.append( val )
        self.getIndexByVal[ val ] = len(self.arr) - 1
        return True

    def remove(self, val: int) -> bool:
        if not val in self.arr:
            return False
        index = self.getIndexByVal[val]
        self.arr[index] = self.arr[-1]
        self.getIndexByVal[ self.arr[index] ] = index
        del self.getIndexByVal[val]
        self.arr.pop()
        return True

    def getRandom(self) -> int:
        return random.choice ( self.arr)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
