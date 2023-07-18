class LRUCache {
public:

    // Helper Node class
    class Node
    {

        public:
        int key;
        int val;
        Node *prev;
        Node *next;

        // constructor
        Node (int key, int val)
        {

            this->key = key;
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    // Helper -> For a circular linked list, needed dummy nodes
    Node    *head = new Node(0, 0);
    Node    *tail = new Node(0, 0);

    // Helper global tracker
    int Cap;
    unordered_map<int, Node *>  Dict;

    // helper fn :  remove . insert

    void    remove( Node *node )
    {

        Dict.erase( node->key );
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void    insert( Node *node )
    {

        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;

        Dict[ node->key ] = node;
    }

    // END of define


    LRUCache(int capacity)
    {

        this->Cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key)
    {

        if ( Dict.find(key) == Dict.end() )
        {
            return (-1);
        }

        Node    *node = Dict[ key ];

        remove( node );
        insert( node );
        return ( node->val );
    }
    
    void put(int key, int value)
    {

        if ( Dict.find(key) != Dict.end() )
        {
            remove( Dict[key] );
        }
        if ( Dict.size() == this->Cap )
        {
            remove( tail->prev );
        }
        insert( new Node( key, value ));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
