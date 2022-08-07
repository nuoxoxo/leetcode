var deleteDuplicates = function(head) {
    if (!head || !head.next)
        return head
    let dumm = new ListNode()
    let slow = dumm
    let fast = head
    while (fast) {
        if (fast.next && fast.val == fast.next.val) {
            while (fast.next && fast.val == fast.next.val) {
                fast = fast.next
            }
        } else {
            slow.next = fast
            slow = fast
        }
        fast = fast.next
    }
    slow.next = null

    return dumm.next
};
