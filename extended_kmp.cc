#include<bits/stdc++.h>

using namespace std;

class Extended_KMP {
    private:
        vector<int> next; // next[i] is length of LCA of needle[i..n] and needle[0..n]
        vector<int> match; // match[i] is lengthof LCA of haystack[i..m] and needle[0..n]
    public:
        void getNext(string needle) {
            int len = needle.length();
            int rightmost, j, k;

            next.resize(len);
            j = 0;
            while (j + 1 < len && needle[j] == needle[j + 1]) j ++;
            next[0] = len; 
            next[1] = j;
            k = 1;
            // k is the index for the rightmost check
            for (int i = 2; i < len; i ++) {
                rightmost = k + next[k] - 1;
                // Since needle{0 .. next[k] - 1} == needle{k .. k + next[k] - 1}
                // Hence, it's true that needle[i - k .. next[k] - 1] == needle[i .. rightmost]
                if ( next[i - k] < rightmost - i + 1 ) {
                    // Just use the old result
                    next[i] = next[i - k];
                } else {
                    j = max(0, rightmost - i + 1);
                    while (i + j < len && needle[i + j] == needle[j] ) j ++;
                    next[i] = j;
                    k = i;
                }
            }
        }

        void getExtend(string haystack, string needle) {
            int hayLength = haystack.length();
            int neeLength = needle.length();
            int j, k, rightmost, L;

            getNext(needle);
            match.resize(hayLength);
            j = 0;
            while (j < min(hayLength, neeLength) && needle[j] == haystack[j]) j ++;
            match[0] = j;
            k = 0;
            // k is the index for the rightmost check
            for (int i = 1;i < hayLength; i ++) {
                rightmost = k + match[k] - 1;
                // Since needle{0 .. match[k] - 1} == haystack{{k .. k + match[k] - 1}
                // Hence, it's true that needle[i - k .. match[k] - 1] == haystack[i .. rightmost]
                if ( next[i - k] < rightmost - i + 1 ) {
                    // Just use the old result
                    match[i] = next[i - k];
                } else {
                    j = max(0, rightmost - i + 1);
                    while (i + j < hayLength && j < neeLength && haystack[i + j] == needle[j]) j ++;
                    match[i] = j;
                    k = i;
                }
            }
            for(auto item: next) cout << item << " "; cout << endl;
            for(auto item: match) cout << item << " "; cout << endl;
        }
};

int main() {
    Extended_KMP kmp;
    kmp.getExtend("abacabacabc", "abcabcab");

    return 0;
}

