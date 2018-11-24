import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Heap {
  private List<int[]> arr = new ArrayList<>();
  private HashMap<Integer, Integer> map = new HashMap<>();

  void add(int item, int index) {
    arr.add(new int[]{item, index});
    int ind = arr.size() - 1;
    while (ind > 0 && arr.get(ind / 2)[0] < arr.get(ind)[0]) {
      int[] t = arr.get(ind / 2);
      arr.set(ind / 2, arr.get(ind));
      arr.set(ind, t);
      map.put(arr.get(ind)[1], ind);
      ind /= 2;
    }
    map.put(arr.get(ind)[1], ind);
  }

  int getMax() {
    if (arr.isEmpty()) return -1;
    return arr.get(0)[0];
  }

  void remove(int index) {
    int ind = map.get(index);
    if (ind == arr.size() - 1) {
      arr.remove(arr.size() - 1);
      return;
    } else {
      arr.set(ind, arr.get(arr.size() - 1));
      arr.remove(arr.size() - 1);
    }
    while (ind < arr.size() - 1) {
      int smallest = ind;
      while (ind * 2 + 1 < arr.size() && arr.get(ind * 2 + 1)[0] > arr.get(smallest)[0])
        smallest = ind * 2 + 1;
      while (ind * 2 + 2 < arr.size() && arr.get(ind * 2 + 2)[0] > arr.get(smallest)[0])
        smallest = ind * 2 + 2;
      if (smallest != ind) {
        int[] t = arr.get(smallest);
        arr.set(smallest, arr.get(ind));
        arr.set(ind, t);
        map.put(t[1], ind);
        ind = smallest;
      } else break;
    }
  }
}
