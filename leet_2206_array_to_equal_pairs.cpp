class Solution {
public:
    bool divideArray(vector<int>& n)
    {
        sort(n.begin(), n.end());
        int i = 0, j = n.size() - 1;
        while (i < j)
        {
            if (n[i] != n[i + 1] || n[j] != n[j - 1])
                return false;
            i += 2;
            j -= 2;
        }
        return true;
    }
};
