class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        map<char, int>  E ;
        int             i, j;
        int             oz = order.size();
        int             wz = words.size();

        i = -1;
        while (++i < oz)    E[order[i]] = i ;
        i = -1;
        while (++i < wz - 1)
        {
            string  L = words[i], R = words[i + 1];
            int     Lz = L.length();
            int     Rz = R.length();
    
            j = -1;
            while (++j < L.length())
            {
                if (j == Rz)
                    return false ;
                if (L[j] != R[j])
                {
                    if (E[ L[j] ] > E[ R[j] ])  return false ;
                    break ;
                }
            }
        }
        return true ;
    }
};
