#include<iostream>

using namespace std;

int MCP(string s) {
    int i = 0, j = 1, count = 0;
    int len = s.length();
    int x, y;

    while (i < len && j < len && count < len) {      
        x = i + count;        
        y = j + count;        
        if (x >= len) x -= len;        
        if (y >= len) y -= len;
        if (s[x] == s[y])
            count++;
        else {
            if (s[x] > s[y])
                i = i + count + 1;
            else
                j = j + count + 1;
            count = 0;
        }
        if (j == i)
            j = i + 1;
    }
    return i;                  
}

int main() {
    cout << MCP("bcabcacba") << endl;
    return 0;
}
