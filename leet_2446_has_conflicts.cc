class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        /*
        [a, b]
        [x, y]
        */
        string a = event1[0], b = event1[1];
        string x = event2[0], y = event2[1];
        return x <= a && a <= y || a <= x && x <= b;
        return !(b < x || a > y); // alt.
    }
};
