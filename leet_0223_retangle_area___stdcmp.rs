impl Solution {
    pub fn compute_area(ax1: i32, ay1: i32, ax2: i32, ay2: i32, bx1: i32, by1: i32, bx2: i32, by2: i32) -> i32 {

        use std::cmp;

        let mut area_a = (ax2 - ax1).abs() * (ay2 - ay1).abs();
        let mut area_b = (bx2 - bx1).abs() * (by2 - by1).abs();
        let mut area_ab = area_a + area_b;

        let mut over_x = std::cmp::min(ax2, bx2) - std::cmp::max(ax1, bx1);
        let mut over_y = std::cmp::min(ay2, by2) - std::cmp::max(ay1, by1);
        let mut area_over = 0;
        if over_x > 0 && over_y > 0
        {
            area_over = over_x * over_y;
        }
        area_ab - area_over
    }
}
