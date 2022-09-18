/*    2415. Reverse Odd Levels of Binary TGiven the root of a perfect binary tree, reverse the node values at each odd level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node.

 

Example 1:


Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]
Explanation: 
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.ree
Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node.

 

Example 1:


Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]
Explanation: 
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.
*/
public void func(TreeNode root1, TreeNode root2, int height){
        if(root1 == null || root2 == null){
            return ;
        }
        
        if(height % 2 == 0){
            int temp = root1.val;
            root1.val = root2.val;
            root2.val = temp;
        }
        
        func(root1.left, root2.right, height + 1);
        func(root1.right, root2.left, height + 1);
    }
    
    public TreeNode reverseOddLevels(TreeNode root) {
        func(root.left, root.right, 0);
        return root;
    }
