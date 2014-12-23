#include<iostream>
#include<cassert>

using namespace std;

size_t strlen(const char *str) {
    const char * cp = str;
    for(;*cp;cp++);
    return (cp-str);
}

char *strcpy(char *to, const char* from) {
    assert(to!=NULL && from !=NULL);
    char *cp = to;
    for(;*from;from++, to++) {
        *to = *from;
    }
    return cp;
}

void calc(const char *needle, int next[]) {
    next[0] = -1;
    next[1] = 0;
    int pos = 1, pos_i = 0;
    while(pos+pos_i < strlen(n)-1) {
        if(needle[pos+pos_i]==needle[pos_i]) {
            pos_i ++;
            next[pos+pos_i] = pos_i;
        }
        else {
            if(next[pos_i]>0) pos_i = next[pos_i];
            else {
                pos_i ++;
                next[pos_i] = 0;
            }
        }
    }
}

char *strStr(const char *haystack, const char *needle) {
    int next[strlen(haystack)];
    calc(needle, next);
    int pos = 0, pos_i = 0;
    while(pos + pos_i < strlen(haystack)) {
        if(haystack[pos + pos_i] == needle[pos_i]) {
            if(pos_i == strlen(haystack)-1) return pos;
            pos_i ++;
        }
        else {
            if(next[pos_i]>-1) {
                pos += pos_i - next[pos_i];
                pos_i = next[pos_i];
            }
            else {
                pos_i = 0;
                pos++;
            }
        }
    }
}

int atoi(const char *str) {
    bool sign = 1;
    int ans = 0;

    while (*str == ' ') str++;
    if (*str == '+') str++;
    if (*str == '-') {
        sign = 0;
        str ++;
    }
    for(; *str != '\0'; str++) {
        if(*str<'0' || *str>'9') break;
        if(num>INT_MAX / 10 || (num==INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
            return sign == -1 ? INT_MIN : INT_MAX;
        }
    }
    return num * sign;
}

int main() {
    char a[10];
    char b[10];
    strcpy(b, "123");
    strcpy(a, b);
    cout << a << endl;

    return 0;
}

