/***
 * An inorder traversal can be implemented using recursion or stack (see previous post). But both methods requires O(h) space, where h is the height of the tree. That said, the worst case space complexity can be O(n).
 *
 * Morris Traversal introduced a way to implement inorder traversal without recursion or stack.
 *
 * It first modify the tree to a partial Threaded Binary Tree where all right child pointers that were null in the original tree are pointed to their inorder successor.
 * With that information in hand, it is much easier to conduct an inorder traversal: Go to the left most node, and follow right pointers to complete the traversal.
 * During the traversal, Morris algorithm then fix the modified right pointers and set them back to null.
 *
 * This algorithm touches each node at most three times: find successor, visit, fix right pointer of pre node. So, it runs in time O(n) and uses O(1) space!
 * ***/
private void inorderMorris(TreeNode root, ArrayList<Integer> values) {  
   TreeNode cur = root;  
   
   while (cur != null) {  
     if (cur.left != null) {  
       TreeNode pre = cur.left;  
       while (pre.right != null && pre.right != cur) {  
         pre = pre.right;  
       }  
       if (pre.right == null) { // set right to successor  
         pre.right = cur;  
         cur = cur.left;  
       } else { // visit and revert the change  
         pre.right = null;  
         values.add(cur.val);  
         cur = cur.right;  
       }  
     } else { // visit and move to successor 
       values.add(cur.val);  
       cur = cur.right;  
     }  
   }  
 }  
