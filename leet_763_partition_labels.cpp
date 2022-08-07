class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> last_index(26);
        vector<int> res ;
        int         len = s.length(), i, j, last, temp;

        i = -1;
        while (++i < len)
            last_index[ s[i] - 'a' ] = i;
        i = 0;
        while (i < len)
        {
            last = last_index[ s[i] - 'a' ];
            if (last == len - 1)
            {
                res.push_back(len - i);
                return res ;
            }
            j = i;
            while (j < last)
            {
                temp = last_index[ s[j] - 'a' ];
                last = last > temp ? last : temp ;
                ++ j ;
            }
            res.push_back(j - i + 1) ;
            i = j + 1;
        }
        return res ;
    }
};
