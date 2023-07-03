impl Solution {
    pub fn buddy_strings(s: String, g: String) -> bool {
        let l = s.len();
        if l != g.len() {
            return false;
        }
        if s == g && l != s.chars().collect::<std::collections::HashSet<_>>().len() {
            return true;
        }
        let mut d: Vec<usize> = Vec::new();
        for (i, (sc, gc)) in s.chars().zip(g.chars()).enumerate() {
            if sc == gc {
                continue;
            }
            d.push(i);
            if d.len() > 2 {
                return false;
            }
        }
        if d.len() != 2 || s.chars().nth(d[0]) != g.chars().nth(d[1]) || s.chars().nth(d[1]) != g.chars().nth(d[0]) {
            return false;
        }
        true
    }
}
