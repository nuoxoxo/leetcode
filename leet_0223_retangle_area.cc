class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int     area_a, area_b, area_ab;
        int     over_x, over_y, area_over;

        area_a = abs(ax2 - ax1) * abs(ay2 - ay1);
        area_b = abs(bx2 - bx1) * abs(by2 - by1);
        area_ab = area_a + area_b;

        over_x = min(ax2, bx2) - max(ax1, bx1);
        over_y = min(ay2, by2) - max(ay1, by1);
        area_over = over_x < 1 || over_y < 1 ? 0 : over_x * over_y;

        return area_ab - area_over;
    }
};
