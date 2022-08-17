class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        set<string>     s;

        for (string w : words)
            s.insert(matching(w));
        return s.size();
    }
    
    string  matching(string s)
    {
        vector<string>  morse;
        string          res;

        res = "";
        morse = {
            ".-",
            "-...",
            "-.-.",
            "-..",
            ".",
            "..-.",
            "--.",
            "....",
            "..",
            ".---",
            "-.-",
            ".-..",
            "--",
            "-.",
            "---",
            ".--.",
            "--.-",
            ".-.",
            "...",
            "-",
            "..-",
            "...-",
            ".--",
            "-..-",
            "-.--",
            "--.."
            };

        for (char c : s)
            res += morse[c - 'a'];
        return res ;
    }
};

/*

a-z mapping:

".-",
"-...",
"-.-.",
"-..",
".",
"..-.",
"--.",
"....",
"..",
".---",
"-.-",
".-..",
"--",
"-.",
"---",
".--.",
"--.-",
".-.",
"...",
"-",
"..-",
"...-",
".--",
"-..-",
"-.--",
"--.."
*/
