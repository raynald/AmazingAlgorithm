#include<string>
#include<iostream>

using namespace std;

void compute(string W, int next[]) {
    int pos = 2;
    int pre = 0;
    next[0] = -1;
    next[1] = 0;
    while(pos < W.length()) {
        if(W[pos-1] == W[pre]) {
            pre ++;
            next[pos] = pre;
            pos++;
        }
        else {
            if(pre>0) pre = next[pre];
            else {
                next[pos] = 0;
                pos ++;
            }
        }
    }
}

int kmp_search(string S, string W) {
    int pos = 0;
    int pos_i = 0;
    int next[W.length()];

    compute(W, next);
    while (pos + pos_i < S.length()) {
        if(S[pos + pos_i] == W[pos_i]) {
            if(pos_i == W.length() - 1) return pos;
            pos_i ++;
        }
        else {
            if(next[pos_i] > -1) {
                pos = pos + pos_i - next[pos_i];
                pos_i = next[pos_i];
            }
            else {
                pos_i = 0;
                pos ++;
            }
        }
    }
    return S.length();
}

int main() {
    cout << kmp_search("abcabcababc", "abababc")<<endl;
}

