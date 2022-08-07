class Solution {
    public int maxScore(int[] p, int k) {
        int best = 0;
        int i = -1;
        while (++i < k) {
            best += p[i];
        }
        int temp = best;
        int n = p.length;
        i = 0;
        while (++i < k + 1) {
            temp += p[n - i];
            temp -= p[k - i];
            best = best > temp ? best : temp;
        }
        return best;
    }
}
