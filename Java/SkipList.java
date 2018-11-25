import java.util.Random;

public class SkipList<T> {
  class SkipListNode<T> {

    int key;
    T value;
    SkipListNode<T> up, down, left, right;
    static final int HEAD_KEY = Integer.MIN_VALUE;
    static final int TAIL_KEY = Integer.MAX_VALUE;

    SkipListNode(int k, T v) {
      key = k;
      value = v;
    }

    int getKey() {
      return key;
    }

    public void setKey(int key) {
      this.key = key;
    }

    T getValue() {
      return value;
    }

    public void setValue(T value) {
      this.value = value;
    }

    public boolean equals(Object o) {
      if (this == o) {
        return true;
      }
      if (o == null) {
        return false;
      }
      if (!(o instanceof SkipListNode<?>)) {
        return false;
      }
      SkipListNode<T> ent;
      try {
        ent = (SkipListNode<T>) o;
      } catch (ClassCastException ex) {
        return false;
      }
      return (ent.getKey() == key) && (ent.getValue() == value);
    }

    @Override
    public String toString() {
      return "key-value:" + key + "-" + value;
    }
  }

  private SkipListNode<T> head, tail;
  private int nodes;
  private int listLevel;
  private Random random;
  private static final double PROBABILITY = 0.5;

  public SkipList() {
    random = new Random();
    clear();
  }

  public void clear() {
    head = new SkipListNode<T>(SkipListNode.HEAD_KEY, null);
    tail = new SkipListNode<T>(SkipListNode.TAIL_KEY, null);
    horizontalLink(head, tail);
    listLevel = 0;
    nodes = 0;
  }

  public boolean isEmpty() {
    return nodes == 0;
  }

  public int size() {
    return nodes;
  }

  private SkipListNode<T> findNode(int key) {
    SkipListNode<T> p = head;
    while (true) {
      while (p.right.key != SkipListNode.TAIL_KEY && p.right.key <= key) {
        p = p.right;
      }
      if (p.down != null) {
        p = p.down;
      } else {
        break;
      }
    }
    return p;
  }

  public SkipListNode<T> search(int key) {
    SkipListNode<T> p = findNode(key);
    if (key == p.getKey()) {
      return p;
    } else {
      return null;
    }
  }

  public void put(int k, T v) {
    SkipListNode<T> p = findNode(k);
    if (k == p.getKey()) {
      p.value = v;
      return;
    }
    SkipListNode<T> q = new SkipListNode<T>(k, v);
    backLink(p, q);
    int currentLevel = 0;
    while (random.nextDouble()
        < PROBABILITY) {
      if (currentLevel >= listLevel) {
        listLevel++;
        SkipListNode<T> p1 = new SkipListNode<T>(SkipListNode.HEAD_KEY, null);
        SkipListNode<T> p2 = new SkipListNode<T>(SkipListNode.TAIL_KEY, null);
        horizontalLink(p1, p2);
        vertiacallLink(p1, head);
        vertiacallLink(p2, tail);
        head = p1;
        tail = p2;
      }
      while (p.up == null) {
        p = p.left;
      }
      p = p.up;
      SkipListNode<T> e = new SkipListNode<T>(k, null);
      backLink(p, e);
      vertiacallLink(e, q);
      q = e;
      currentLevel++;
    }
    nodes++;
  }

  private void backLink(SkipListNode<T> node1, SkipListNode<T> node2) {
    node2.left = node1;
    node2.right = node1.right;
    node1.right.left = node2;
    node1.right = node2;
  }

  private void horizontalLink(SkipListNode<T> node1, SkipListNode<T> node2) {
    node1.right = node2;
    node2.left = node1;
  }

  private void vertiacallLink(SkipListNode<T> node1, SkipListNode<T> node2) {
    node1.down = node2;
    node2.up = node1;
  }

  @Override
  public String toString() {
    if (isEmpty()) {
      return "Empty SkipList";
    }
    StringBuilder builder = new StringBuilder();
    SkipListNode<T> p = head;
    while (p.down != null) {
      p = p.down;
    }
    while (p.left != null) {
      p = p.left;
    }
    if (p.right != null) {
      p = p.right;
    }
    while (p.right != null) {
      builder.append(p);
      builder.append("\n");
      p = p.right;
    }
    return builder.toString();
  }
}



