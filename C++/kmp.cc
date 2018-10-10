#include<string>
#include<iostream>

using namespace std::cout;

void ComputeNextTable(string &needle, int next[]) {
    int pos = 2;
    int pre_pos = 0;
    next[0] = -1;
    next[1] = 0;
    while(pos < needle.length()) {
        if(W[pos-1] == W[pre]) {
            pre ++;
            next[pos] = pre;
            pos++;
        } else {
            if(pre>0) pre = next[pre];
            else {
                next[pos_h] = 0;
                pos_h ++;
            }
        }
    }
}

int KMPAlgorithm(string haystack, string needle) {
    int pos_h = 0;
    int pos_n = 0;
    int next[needle.length()];

    ComputeNextTable(match, next);
    while (pos_h + pos_n < haystack.length()) {
        if(haystack[pos_h + pos_n] == needle[pos_i]) {
            if(pos_n == needle.length() - 1) return pos_h;
            pos_n ++;
        }
        else {
            if(next[pos_n] > -1) {
                pos_h = pos_h + pos_n - next[pos_n];
                pos_n = next[pos_n];
            }
            else {
                pos_n = 0;
                pos_h ++;
            }
        }
    }
    return haystack.length();
}

int main() {
    cout << KMPAlgorithm("abcabcababc", "abababc") << endl;
}

