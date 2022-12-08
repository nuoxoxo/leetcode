// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn leaf_similar (
        root1: Option<Rc<RefCell<TreeNode>>>, 
        root2: Option<Rc<RefCell<TreeNode>>>
    ) -> bool {
        fn dfs_on_single_node
        (
            node: &Option<Rc<RefCell<TreeNode>>>, 
            v: &mut Vec<i32>
        )
        {
            if let Some(ptr) = node
            {
                let ptr = ptr.borrow();
                if ptr.left.is_none() && ptr.right.is_none()
                {
                    v.push(ptr.val);
                    return ;
                }
                dfs_on_single_node( &ptr.left, v);
                dfs_on_single_node( &ptr.right, v);
            }
        }
        let mut a1 = Vec::new();
        let mut a2 = Vec::new();
        dfs_on_single_node( &root1, &mut a1);
        dfs_on_single_node( &root2, &mut a2);
        a1 == a2
    }
}
