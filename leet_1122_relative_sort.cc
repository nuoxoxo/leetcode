class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> D;
        vector<int> tail;
        vector<int> res;

        for (int n: arr1) {
            if (find(arr2.begin(), arr2.end(), n) == arr2.end()) {
                tail.push_back(n);
            }
        }

        sort(tail.begin(), tail.end());

        for (int n: arr1) {
            if (D.find(n) != D.end()) {
                D[n]++;
            } else {
                D[n] = 1;
            }
        }

        for (int n: arr2) {
            res.insert(res.end(), D[n], n);
        }

        res.insert(res.end(), tail.begin(), tail.end());
        return res;
    }
};
