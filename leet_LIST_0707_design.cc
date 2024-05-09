// class ListNode {
// public:
//     int val;
//     ListNode * next;
//     Node (int val) : val(val), next( nullptr ){}
// };

// DIY - ListNode as a single node


class MyLinkedList {
public:

    ListNode * top;
    int size;

    MyLinkedList () : top( nullptr ), size(0){}
    
    int get(int index)
    {
        if (index < 0 || index > this->size - 1)
            return -1;
        ListNode * node = this->top;
        int i = -1;
        while (++i < index)
            node = node->next;
        return node->val;
    }
    
    void addAtHead(int val)
    {
        ListNode * new_head = new ListNode (val);
        new_head->next = this->top;
        this->top = new_head;
        this->size++;
    }
    
    void addAtTail(int val)
    {
        if ( !this->top)
        {
            this->top = new ListNode (val);
            this->size = 1;
            return ;
        }
        ListNode * node = this->top;
        while (node->next)
            node = node->next;
        node->next = new ListNode (val);
        this->size++;
    }
    
    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > this->size)
            return ;
        ListNode * todo = new ListNode (val);
        if (index < 1)
        {
            todo->next = this->top;
            this->top = todo;
            this->size++;
            return ;
        }
        ListNode * node = this->top;
        int i = -1;
        while (++i < index - 1)
            node = node->next;
        todo->next = node->next;
        node->next = todo;
        this->size++;
    }
    
    void deleteAtIndex(int index)
    {
        if (index < 0 || index > this->size - 1)
            return ;
        if (index == 0)
        {
            this->top = this->top->next;
            this->size--;
            return ;
        }
        ListNode * node = this->top;
        int i = -1;
        while (++i < index - 1)
            node = node->next;
        node->next = node->next->next;
        this->size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
