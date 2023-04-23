class Solution {
public:
    vector<int> searchRange(vector<int>& n, int t)
    {
        vector<int>::iterator   L, R;

        L = std::lower_bound(n.begin(), n.end(), t);
        R = std::upper_bound(n.begin(), n.end(), t);
        if (L == n.end() || *L ^ t)
            return {-1, -1} ;
	    if (R == n.end())
            return {(int) (L - n.begin()), (int) n.size() - 1} ;
        return {(int) (L - n.begin()), (int) (R - 1 - n.begin())} ;
    }
};
