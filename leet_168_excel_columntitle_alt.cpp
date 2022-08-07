class Solution {
public:
    string convertToTitle(int col)
    {
        string  s = "";

        while (col)
        {
            col --;
            s += col % 26 + 'A';
            col /= 26;
        }
        reverse(s.begin(), s.end()) ;

        return s ;
    }
};

