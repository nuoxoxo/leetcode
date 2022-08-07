var removeElements = function(head, val)
{
    let temp, p;

    while (head && head.val === val) {
        temp = head;
        head = head.next;
        temp.next = null;
    }
    p = head;
    while (p && p.next){
        if (p.next.val === val){
            temp = p.next;
            p.next = p.next.next;
            temp.next = null;
        }
        else    p = p.next;
    }
    return head;
};
