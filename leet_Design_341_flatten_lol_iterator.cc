/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    
    vector<int> v;
    int         s;
    
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        flatten(nestedList);
        s = v.size();
    }
    
    int next()
    {
        int res ;
        if (s)
        {
            res = v[0];
            v.erase(v.begin());
            --s;
        }
        return res;
    }
    
    bool hasNext()
    {
        return s > 0;
    }

    //  create one more helper func
    void    flatten(vector<NestedInteger> &nestedList)
    {
        for (auto n: nestedList)
        {
            if (n.isInteger())
                v.push_back(n.getInteger());
            else
                flatten(n.getList());
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
