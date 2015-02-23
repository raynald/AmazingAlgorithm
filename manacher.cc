#include<iostream>
#include<vector>
#include<string>

using namespace std;

string lps(string input) {
    //create s
    string s = "#";
    for(int i = 0;i < input.length();i ++) {
        s = s + input[i] + "#";
    }
    int p[s.length()];
    memset(p, 0, sizeof(p));
    int mx = 0; // border
    int id = 0; // center
    for (int i=0;i<s.length();i ++) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        // Complexity O(n), three cases:
        //  mx - i: new charactesr
        //  p[2 * id -i]: O(1)
        //  1: new characters
        while (i + p[i] < s.length() && i >= p[i] && s[i + p[i]] == s[i - p[i]]) p[i] ++;
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
    int ans = 0;
    string re;
    for (int i=0;i<s.length();i ++) {
        if (p[i] > ans) {
            ans = p[i];
            re = input.substr((i - p[i] + 2) / 2 , p[i] - 1); 
        }
    }
    return re;
}

int main() {
    cout << lps("abbabcba") << endl;
    cout << lps("fababe") << endl;
    cout << lps("a") << endl;
    return 0;
}

