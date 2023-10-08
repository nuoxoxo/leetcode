class MyHashMap {
public:
    vector<int> K;
    vector<int> V;
    int Size = 0;

    MyHashMap() {
        
    }
    
    void put(int key, int value)
    {
        int i = -1;
        while (++i < Size)
        {
            if (K[i] == key)
            {
                V[i] = value;
                return;
            }
        }
        K.push_back(key);
        V.push_back(value);
        Size++;
    }
    
    int get(int key)
    {
        int i = -1;
        while (++i < Size)
        {
            if (K[i] == key)
                return V[i];
        }
        return -1;
    }
    
    void remove(int key)
    {
        int i = -1;
        while (++i < Size)
        {
            if (K[i] == key)
            {
                K.erase(K.begin() + i);
                V.erase(V.begin() + i);
                Size--;
                break ;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
