import java.util.Comparator;

public class SplayTree<T extends Comparable<T>> {

  class SplayTreeNode<T extends Comparable<T>> {

    SplayTreeNode<T> left;
    SplayTreeNode<T> right;
    T data;

    SplayTreeNode(SplayTreeNode<T> left, SplayTreeNode<T> right, T data) {
      this.left = left;
      this.right = right;
      this.data = data;
    }

    SplayTreeNode() {
      this(null, null, null);
    }

    SplayTreeNode(T data) {
      this(null, null, data);
    }
  }

  private SplayTreeNode<T> root;
  private Comparator<T> cmp;

  public SplayTree() {
    root = null;
  }

  public SplayTree(Comparator<T> cmp) {
    this.cmp = cmp;
  }

  private int mCompare(T a, T b) {
    if (cmp != null) {
      return cmp.compare(a, b);
    }
    return a.compareTo(b);
  }

  public SplayTreeNode<T> insert(T data) {
    root = insert(root,
        data); //进行伸展
    root = splay(root, data);
    return root;
  }

  private SplayTreeNode<T> insert(SplayTreeNode<T> tree, T data) {
    if (tree == null) {
      return new SplayTreeNode<T>(data);
    }
    int result = mCompare(data, tree.data);
    if (result < 0) {
      tree.left = insert(tree.left, data);
    } else if (result > 0) {
      tree.right = insert(tree.right, data);
    } else {
      System.out.println("data exists");
      return null;
    }
    return tree;
  }

  private SplayTreeNode<T> insert(SplayTreeNode<T> rootTree, SplayTreeNode<T> tempNode) {
    if (rootTree == null) {
      return tempNode;
    } else {
      int result = mCompare(tempNode.data, rootTree.data);
      if (result < 0) {
        rootTree.left = insert(rootTree.left, tempNode);
      } else if (result > 0) {
        rootTree.right = insert(rootTree.right, tempNode);
      }
    }
    return rootTree;
  }

  public SplayTreeNode<T> search(T data) {
    return search(root, data);
  }

  private SplayTreeNode<T> search(SplayTreeNode<T> tree, T data) {
    if (tree == null) {
      return null;
    }
    int result = mCompare(data, tree.data);
    if (result < 0) {
      return search(tree.left, data);
    } else if (result > 0) {
      return search(tree.right, data);
    } else {
      root = splay(root, data);
      return tree;
    }
  }

  public T getRoot() {
    return root != null ? root.data : null;
  }

  public T findMax() {
    return findMax(root).data;
  }

  private SplayTreeNode<T> findMax(SplayTreeNode<T> tree) {
    if (tree == null) {
      return null;
    }
    while (tree.right != null) {
      tree = tree.right;
    }
    return tree;
  }

  public SplayTreeNode<T> remove(T data) {
    SplayTreeNode<T> newRoot, removeRoot;
    if (root == null) {
      return null;
    }
    removeRoot = search(root, data);
    if (removeRoot == null) {
      return null;
    }
    root = splay(root, data);
    if (root.left != null) {
      newRoot = splay(root.left, findMax(
          root.left).data);
      newRoot.right = root.right;
    } else {
      newRoot = root.right;
    }
    root = newRoot;
    return removeRoot;
  }

  public SplayTreeNode<T> splay(SplayTreeNode<T> tree, T data) {
    if (tree == null) {
      return null;
    }
    int result = mCompare(data, tree.data);
    if (result < 0) {
      tree.left = splay(tree.left, data);
      tree = rotationRight(tree);
    } else if (result > 0) {
      tree.right = splay(tree.right, data);
      tree = rotationLeft(tree);
    } else {
      return tree;
    }
    return tree;
  }

  private SplayTreeNode<T> rotationLeft(SplayTreeNode<T> root) {
    SplayTreeNode<T> newRoot = root.right;
    root.right = newRoot.left;
    newRoot.left = root;
    return newRoot;
  }

  private SplayTreeNode<T> rotationRight(SplayTreeNode<T> tree) {
    SplayTreeNode<T> newRoot = tree.left;
    tree.left = newRoot.right;
    newRoot.right = tree;
    return newRoot;
  }

  public void inOrder() {
    inOrder(root);
  }

  private void inOrder(SplayTreeNode<T> tree) {
    if (tree != null) {
      inOrder(tree.left);
      System.out.print(tree.data + " ");
      inOrder(tree.right);
    }
  }
}
