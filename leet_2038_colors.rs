impl Solution {
    pub fn winner_of_game(colors: String) -> bool {
        if colors.len() < 3 {
            return false;
        }
        let mut a = 0;
        let mut b = 0;
        let chars: Vec<char> = colors.chars().collect();
        for i in 1..colors.len() - 1 {
            if chars[i - 1] == chars[i] && chars[i] == chars[i + 1] {
                if chars[i] == 'A' {
                    a += 1;
                } else {
                    b += 1;
                }
            }
        }

        a > b
    }
}
