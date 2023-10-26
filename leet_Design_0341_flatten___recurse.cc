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

vector<int> _vec;
int     _len;

public:

    void    m_flatten(vector<NestedInteger> & nestedList)
    {
        for (auto item: nestedList)
        {
            if (item.isInteger())
                _vec.push_back(item.getInteger());
            else
                m_flatten(item.getList());
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList)
    {
        m_flatten(nestedList);
        _len = (int) _vec.size();
    }
    
    int next()
    {
        int res; // non init - undefined bhv.
        if (_len)
        {
            res = _vec[0];
            _vec.erase(_vec.begin());
            _len--;
        }
        return res;
    }
    
    bool hasNext() const { return _len > 0; }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
