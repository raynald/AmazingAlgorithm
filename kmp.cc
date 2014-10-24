void compute(string W, int T[]) {
    int pos = 2;
    int cnd = 0;
    T[0] = -1;
    T[1] = 0;
    while(pos < W.length()) {
        if(W[pos-1] == W[cnd]) {
            cnd ++;
            T[pos] = cnd;
            pos ++;
        }
        else if(cnd > 0) cnd = T[cnd];
        else {
            T[pos] = 0;
            pos ++;
        }
    }
}

int kmp_search(string S, string W) {
    int m = 0;
    int i = 0;

    compute();
    while (m + i < S.length()) {
        if(W[i] == S[m+i]) {
            if(i == W.length() - 1) return m;
            i ++;
        }
        else {
            if(T[i] > -1) {
                m = m + i - T[i];
                i = T[i];
            }
            else {
                i = 0;
                m ++;
            }
        }
    }
}

