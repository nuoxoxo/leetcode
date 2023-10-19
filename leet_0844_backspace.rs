impl Solution {
    pub fn backspace_compare(s: String, t: String) -> bool {
        let mut ss = Vec::new();
        let mut tt = Vec::new();
        
        for c in s.chars() {
            if c != '#' {
                ss.push(c);
            } else if ss.len() > 0 {
                ss.pop();
            }
        }

        for c in t.chars() {
            if c != '#' {
                tt.push(c);
            } else if tt.len() > 0 {
                tt.pop();
            }
        }

        ss == tt
    }
}
