class RandomizedSet:

    def __init__(self):
        self.S = set()

    def insert(self, val: int) -> bool:
        if val in self.S:
            return False
        self.S.add(val)
        return True

    def remove(self, val: int) -> bool:
        if not val in self.S:
            return False
        self.S.discard(val)
        return True

    def getRandom(self) -> int:
        return random.choice( list(self.S) )

# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
