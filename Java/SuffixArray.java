import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;


public class SuffixArray {

  private int[] indexArray;
  private String origin;

  static class Compare implements Comparator<int[]> {

    @Override
    public int compare(int[] x, int[] y) {
      return x[1] == y[1] ? x[2] - y[2] : x[1] - y[1];
    }
  }

  public void build(String txt) {
    origin = txt;
    int n = txt.length();
    List<int[]> suffix = new ArrayList<>();
    int[] pos = new int[n];

    for (int i = 0; i < n; i++) {
      int[] temp = {i, txt.charAt(i) - 'a', i < n - 1 ? txt.charAt(i + 1) : -1};
      suffix.add(temp);
    }
    suffix.sort(new Compare());
    for (int k = 2; k < n; k = k * 2) {
      int rank = 0;
      int prev_rank = -1;
      pos[suffix.get(0)[0]] = 0;
      for (int i = 1; i < n; i++) {
        if (suffix.get(i)[1] == prev_rank && suffix.get(i)[2] == suffix.get(i - 1)[2]) {
          suffix.get(i)[1] = rank;
        } else {
          prev_rank = suffix.get(i)[1];
          suffix.get(i)[1] = ++rank;
        }
        pos[suffix.get(i)[0]] = i;
      }
      for (int i = 0; i < n; i++) {
        int index = suffix.get(i)[0];
        suffix.get(i)[2] = index + k < n ? suffix.get(pos[index + k])[1] : -1;
      }
      suffix.sort(new Compare());
    }
    indexArray = new int[n];
    for (int i = 0; i < n; i++) {
      indexArray[i] = suffix.get(i)[0];
    }
  }

  int search(String key) {
    int left = 0;
    int right = origin.length() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      int val = key.compareTo(origin.substring(indexArray[mid], indexArray[mid] + key.length()));
      if (val == 0) return indexArray[mid];
      if (val < 0) right = mid - 1; else left = mid + 1;
    }
    return -1;
  }
}
