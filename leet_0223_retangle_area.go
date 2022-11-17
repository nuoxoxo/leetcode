func Max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func Min(x, y int) int {
	if x > y {
		return y
	}
	return x
}

func Abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// There is no built-in abs, min or max functions for int, simply write your own

func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
    area_a := Abs(ax2 - ax1) * Abs(ay2 - ay1);
    area_b := Abs(bx2 - bx1) * Abs(by2 - by1);
    area_ab := area_a + area_b;

    over_x := Min(ax2, bx2) - Max(ax1, bx1);
    over_y := Min(ay2, by2) - Max(ay1, by1);
    area_over := 0
    if over_x > 0 && over_y > 0 {
        area_over = over_x * over_y
    }
    return area_ab - area_over;
}
