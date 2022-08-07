# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        def flatten(lol): # list of lists
            ni = [] # nested ints
            for n in lol:
                if n.isInteger():
                    ni.append(n.getInteger())
                else:
                    ni.extend(flatten(n.getList()))
            return ni
        self.ni = flatten(nestedList)


    def next(self) -> int:
        if len(self.ni) != 0:
            n = self.ni[0]
            self.ni.pop(0)
            return n


    def hasNext(self) -> bool:
         return len(self.ni) != 0


# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())





