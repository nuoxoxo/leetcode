class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k)
    {
        int         i = num.size();
        vector<int> v ;

        while (--i > -1 || k)
        {
            if (i > -1)
                k += num[i];
            v.push_back(k % 10) ;
            k /= 10 ;
        }
        reverse(v.begin(), v.end()) ;
        return (v);
    }
};
