#include<bits/stdc++.h>

using namespace std;

map<char, int> my_map;

int longest(string str, int k) {
    int i, j;
    char ch;
    int ans = 0;
    i = 0;
    j = 0;
    while(j < str.length()) {
        auto got = my_map.find(str[j]);
        if (got != my_map.end()) {
            got -> second ++;
        } else {
            if(my_map.size() == k) {
                if(j-i>ans) ans = j-i;
                while(my_map.size()!=k-1) {
                    ch = str[i++];
                    got = my_map.find(ch);
                    if(got->second == 1) {
                        my_map.erase(ch);
                    }
                    else got->second --;
                }
            }
            my_map.insert(pair<char, int>(str[j], 1));
        }
        j++;
    }
    if(my_map.size() == k && j-i>ans) ans = j-i;
    return ans;
}

int main() {
    cout << longest("llabdabacdllllle",3) << endl;
    return 0;
}
