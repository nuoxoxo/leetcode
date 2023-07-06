/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    
    Iterator    *it;
    int         currentElement;
    
    
    PeekingIterator(const vector<int>& nums) : Iterator(nums)
    {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	it = new Iterator(nums);
        if (it->hasNext())
        currentElement = it->next();
    }
	
    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        return currentElement;
    }
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
    int next()
    {
        int temp = currentElement;

        if (it->hasNext())
            currentElement = it->next();
        else
            currentElement = INT_MIN;
        return temp;
    }
	
    bool hasNext() const
    {
	return currentElement != INT_MIN;
    }
};
