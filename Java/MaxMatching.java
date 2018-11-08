import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

public class MaxMatching {
  private boolean[] v;
  private int[] A;
  private int[] B;
  private int[] lnk;

  private boolean find(int x) {
    for (int i = 0; i < A.length; i++) {
      if (A[x] > B[i] && !v[i]) {
        v[i] = true;
        if (lnk[i] == -1 || find(lnk[i])) {
          lnk[i] = x;
          return true;
        }
      }
    }
    return false;
  }

  public int[] advantageCount(int[] A, int[] B) {
    this.A = A;
    this.B = B;
    lnk = new int[B.length];
    Arrays.fill(lnk, -1);
    for (int i = 0; i < B.length; i++) {
      v = new boolean[B.length];
      Arrays.fill(v, false);
      find(i);
    }
    HashSet<Integer> h = new HashSet<>();
    for (int i = 0;i < B.length;i ++) {
      if (lnk[i] != -1) h.add(lnk[i]);
    }
    List<Integer> stack = new ArrayList<>();
    for (int i = 0;i < B.length;i ++) {
      if (!h.contains(i)) {
        stack.add(i);
      }
    }
    for (int i = 0;i < B.length;i ++) {
      if (lnk[i] == -1) lnk[i] = stack.remove(stack.size() - 1);
    }
    return lnk;
  }
}
