class OrderedStream {
public:
    vector<string>  vs;
    int             I;
    
    OrderedStream(int n)
    {
        // vs.reserve(n);
        vs.resize(n, ""); // resized & filled w. empty strings
        I = 0;
    }
    
    vector<string> insert(int idKey, string value)
    {
        vector<string>  r;
        int             i;

        vs[idKey - 1] = value;
        i = I - 1;
        while (++i < vs.size())
        {
            if (!vs[i].length())
                break ;
            r.push_back(vs[i]);
            ++I;
        }
        return r;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
