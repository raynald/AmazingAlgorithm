void selection_sort(int *a, int len) {
    int i, j, min, t;
    for(i=0;i < len - 1;i ++) {
        min = i;
        for(j = i+1;j < len;j ++) {
            if(a[min]> a[j]) min = j;
        }
        if (min != i) {
            swap(a[min, a[i]);
        }
    }
}

