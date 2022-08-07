class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        map<Node*, Node*>   E ;
        Node*               curr;

        curr = head;
        while (curr)
        {
            Node    *temp = new Node(curr->val);

            E[curr] = temp ;
            curr = curr->next;
        }
        curr = head;
        while (curr)
        {
            Node    *temp = E[curr];

            temp->next = E[curr->next];
            temp->random = E[curr->random];
            curr = curr->next ;
        }
        return E[head] ;
    }
};
