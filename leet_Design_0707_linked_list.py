class MyLinkedList:

    def __init__(self, val=0):
        self.top = None
        self.size = 0

    def get(self, index: int) -> int:
        if index < 0 or index > self.size - 1:
            return -1
        node = self.top
        for _ in range(index):
            node = node.next
        return node.val

    def addAtHead(self, val: int) -> None:
        new_head = ListNode(val)
        new_head.next = self.top
        self.top = new_head
        self.size += 1

    def addAtTail(self, val: int) -> None:
        if not self.top:
            self.top = ListNode(val)
            self.size = 1
            return
        node = self.top
        while node.next:
            node = node.next
        node.next = ListNode(val)
        self.size += 1

    def addAtIndex(self, index: int, val: int) -> None:
        if index < 0 or index > self.size:
            return
        todo = ListNode(val)
        if index < 1:
            todo.next = self.top
            self.top = todo
            self.size += 1
            return
        node = self.top
        for _ in range(index - 1):
            node = node.next
        todo.next = node.next
        node.next = todo
        self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        if index < 0 or index > self.size - 1:
            return
        if index == 0:
            self.top = self.top.next
            self.size -= 1
            return
        node = self.top
        for _ in range(index - 1):
            node = node.next
        node.next = node.next.next
        self.size -= 1

class ListNode:
    def __init__(self, val=0):
        self.val = val
        self.next = None


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
