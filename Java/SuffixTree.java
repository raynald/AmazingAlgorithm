public class SuffixTree {
  private TreeNode root = null;
  private String originString = "";

  class TreeNode {

    String value = "";
    TreeNode leftChild = null;
    TreeNode sibling = null;

    TreeNode(String x) {
      this.value = x;
    }
  }


  SuffixTree(String str) {
    originString = str;
  }

  public void build() {
    root = new TreeNode("#");
    for (int i = 0;i < originString.length();i ++) {
      insert(root, originString.substring(i));
    }
  }

  private void insert(TreeNode parent, String suffix) {
    TreeNode node = parent.leftChild;
    while (node != null) {
      if (suffix.charAt(0) == node.value.charAt(0)) break;
      node = node.sibling;
    }
    if (node != null) {
      addToTree(parent, suffix);
    } else {
      for (int i = 1;;i ++) {
        if (suffix.length() < i + 1) return;
        if (node.value.length() < i + 1) {
          insert(node, suffix.substring(i));
          return;
        }
        if (suffix.charAt(i) != node.value.charAt(i)) {
          TreeNode oldChild = node.leftChild;
          addToTree(node, node.value.substring(i));
          node.leftChild.sibling = null;
          node.leftChild.leftChild = oldChild;
          addToTree(node, suffix.substring(i));
          node.value = node.value.substring(0, i);
          return;
        }
      }
    }
  }

  private void addToTree(TreeNode parent, String str) {
    TreeNode newNode = new TreeNode(str);
    if (parent.leftChild == null) {
      parent.leftChild = newNode;
    } else {
      newNode.sibling = parent.leftChild;
      parent.leftChild = newNode;
    }
  }
}
