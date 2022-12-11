function computeArea(ax1: number, ay1: number, ax2: number, ay2: number, bx1: number, by1: number, bx2: number, by2: number): number {
    let area_a = Math.abs(ax2 - ax1) * Math.abs(ay2 - ay1);
    let area_b = Math.abs(bx2 - bx1) * Math.abs(by2 - by1);
    let area_ab = area_a + area_b;

    let over_x = Math.min(ax2, bx2) - Math.max(ax1, bx1);
    let over_y = Math.min(ay2, by2) - Math.max(ay1, by1);
    let area_over = 0
    if (over_x > 0 && over_y > 0) {
        area_over = over_x * over_y
    }
    return area_ab - area_over;
};
