class Solution {
public:
    int lengthOfLastWord(string s)
    {
        stringstream    ss(s);
        string          end ;
        int             len ;

        while (getline(ss, end, ' '))
            if (end != "")
                len = end.length() ;

        return len ;
    }
};
