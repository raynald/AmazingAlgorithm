#include<bits/stdc++.h>

using namespace std;

const int R = 256; //alphabet size
const long Q = 0xfff1; //big prime number

//Hash function
long getHash(const string &key) {
    long h = 0;

    for (int j = 0; j < key.length(); ++j) h = (h * R + key[j]) % Q;
    return h;
}

//Rehash
long rehash(const long h, const char first, const char next, const long RM) {
    long newh = (h + Q - RM * first % Q) % Q;
    newh = (newh * R + next) % Q;
    return newh;
}

int check(const string &pattern, const string &substring) {
    for(int i = 0;i < pattern.length();i ++) {
        if (pattern[i] != substring[i]) return 0;
    }
    return 1;
}

int rabinKarp(const string &text, const string &pattern) {
    const long pattern_hash = getHash(pattern);
    long text_hash = getHash(text.substr(0, pattern.length()));
    int RM = 1;
    for (int i = 0; i < pattern.length() - 1; ++ i) RM = (RM * R) % Q;
    for (int i = 0; i <= text.length() - pattern.length(); ++ i) {
        if (text_hash == pattern_hash) {
            if (check(pattern, &text[i])) return i;
        }
        text_hash = rehash(text_hash, text[i], text[i + pattern.length()], RM);
    }
    return -1;
}

int main() {
    string text = "HERE IS A SIMPLE EXAMPLE";
    string pattern = "EXAMPLE";
    const int pos = rabinKarp(text, pattern);
    printf("%d\n", pos); /* expect 17 */

    return 0;
}

