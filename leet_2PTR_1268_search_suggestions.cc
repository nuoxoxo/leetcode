class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>  res;
        sort(products.begin(), products.end());
        int n = (int) products.size();
        int wl = (int) searchWord.size();
        int L = 0;
        int R = n - 1;
        int i = -1;
        while (++i < wl)
        {
            char c = searchWord[i];
            while (L <= R && (i >= products[L].size() || products[L][i] < c))
                ++L;
            while (L <= R && (i >= products[R].size() || products[R][i] > c))
                --R;
            if (L > R)
                res.push_back({});
            else
            {
                int end = L + 3 > R + 1 ? R + 1 : L + 3; 
                res.push_back(vector<string>(
                    products.begin() + L, 
                    products.begin() + end
                ));
            }
        }
        return res;
    }
};
