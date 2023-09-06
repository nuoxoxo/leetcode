/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function splitListToParts(head: ListNode | null, k: number): Array<ListNode | null> {
    let res:Array<ListNode | null> = []
    let N:number = 0
    let p:ListNode = head
    while (p) {
        ++N
        p = p.next
    }
    let slotSize:number = Math.floor(N / k)
    let remainingSlots:number = N % k;
    let i = -1, j
    p = head
    while (++i < k) {
        res.push(p)
        let tailMaybe:ListNode | null = null
        j = -1
        while (++j < slotSize) {
            if (!p)
                continue
            tailMaybe = p
            p = p.next
        }
        if (p && remainingSlots) {
            tailMaybe = p
            p = p.next
            --remainingSlots
        }
        if (tailMaybe) {
            tailMaybe.next = null
        }
    }
    return res
};
