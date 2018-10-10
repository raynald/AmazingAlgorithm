class QuickSort {
  void sort(int[] data, int left, int right) {
    int pivot = data[left];
    int i = left;
    int j = right;
    while (j > i) {
      while (j > i && data[j] > pivot) {
        j --;
      }
      if (j > i) {
        data[i] = data[j];
        i ++;
      }
      while (j > i && data[i] < pivot) {
        i ++;
      }
      if (j > i) {
        data[j] = data[i];
        j --;
      }
    }
    data[i] = pivot;
    if (i < right) sort(data, i + 1, right);
    if (i > left) sort(data, left, i - 1);
  }
}
