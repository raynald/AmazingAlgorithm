public class SparseTable {
  private int[][] s;

  SparseTable(int[] num, int MAX_LOG, int n) {
    s = new int[n][MAX_LOG];;
    int step = 1;
    for (int j = 0;j < MAX_LOG;j ++) {
      for (int i = 0;i < n;i ++) {
        if (i + step - 1 >= n) break;
        s[i][j] = j == 0 ? num[i]: Math.min(s[i][j - 1], s[i + step / 2][j - 1]);
      }
      step *= 2;
    }
  }

  public int getMin(int left, int right) {
    int bits = (int) (Math.log(right - left + 1)/Math.log(2));
    return s[left][bits] + s[right - 1 << bits + 1][bits];
  }
}
