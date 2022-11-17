/**
 * @param {number} ax1
 * @param {number} ay1
 * @param {number} ax2
 * @param {number} ay2
 * @param {number} bx1
 * @param {number} by1
 * @param {number} bx2
 * @param {number} by2
 * @return {number}
 */

var computeArea = function(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) {
    area_a = Math.abs(ax2 - ax1) * Math.abs(ay2 - ay1);
    area_b = Math.abs(bx2 - bx1) * Math.abs(by2 - by1);
    area_ab = area_a + area_b;

    over_x = Math.min(ax2, bx2) - Math.max(ax1, bx1);
    over_y = Math.min(ay2, by2) - Math.max(ay1, by1);
    area_over = 0
    if (over_x > 0 && over_y > 0) {
        area_over = over_x * over_y
    }
    return area_ab - area_over;
};
