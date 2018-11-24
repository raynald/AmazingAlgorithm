class KMP {
  public int match(String needle, String haystack) {
    int[] next = new int[needle.length()];
    calc(needle, next);
    int pn = 0;
    int ph = 0;
    while (ph < haystack.length()) {
      if (haystack.charAt(ph + pn) == needle.charAt(pn)) {
        pn ++;
        if (pn == needle.length()) return ph;
      } else {
        if (pn > 0) {
          ph = ph + pn - next[pn];
          pn = next[pn];
        } else {
          ph ++;
        }
      }
    }
    return -1;
  }

  private void calc(String needle, int [] next) {
    next[0] = -1;
    next[1] = 0;
    int p = 2;
    int q = 0;
    while (p < needle.length()) {
      if (needle.charAt(p - 1) == needle.charAt(q)) {
        next[p] = q + 1;
        q ++;
        p ++;
      } else {
        if (next[q] >= 0) {
          q = next[q];
        } else {
          next[p] = 0;
          p = p + 1;
        }
      }
    }
  }
}


// a b c d e f
//
