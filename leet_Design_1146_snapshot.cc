class SnapshotArray {
public:

    vector<map<int, int>>   V;
    int g_snap_id = 0;

    SnapshotArray(int length)
    {
        int     i;

        V.resize(length);
        i = -1;
        while (++i < length)
        {
            V[i][0] = 0;
        }        
    }
    
    void set(int index, int val)
    {
        V[index][g_snap_id] = val;
    }
    
    int snap()
    {
        ++g_snap_id;
        return (g_snap_id - 1);
    }
    
    int get(int index, int snap_id)
    {
        if (V[index].find(snap_id) != V[index].end())
            return (V[index][snap_id]);

        map<int, int>::iterator     it;

        it = V[index].lower_bound(snap_id);
        it--;
        return (it->second);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
