class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        set<string> E;
        int i = -1;
        while (++i < words.size())  E.insert(mc(words[i]));
        return E.size() ;
    }
    
    string  mc(string s)
    {
        vector<string>  morse = {".-","-...","-.-.","-..",".","..-.",\
            "--.","....","..",".---","-.-",".-..","--","-.","---",".--.",\
            "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string  res = "";
        int     i = -1;

        while (++i < s.length())
            res += morse[ s[i] - 'a' ];
        return res ;
    }
};
